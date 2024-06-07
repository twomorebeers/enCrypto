//
// Created by bog on 07.06.2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include "CipherPrototypeFactory.h"
#include "CaesarCipher.h"

void encryptFile(const std::string& inputFile, const std::string& outputFile, Cipher* cipher) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);
    std::string line;
    while (std::getline(in, line)) {
        out << cipher->encrypt(line) << '\n';
    }
}

void decryptFile(const std::string& inputFile, const std::string& outputFile, Cipher* cipher) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);
    std::string line;
    while (std::getline(in, line)) {
        out << cipher->decrypt(line) << '\n';
    }
}

int main() {
    CipherPrototypeFactory factory;
    factory.registerCipher("Caesar", new CaesarCipher(5));

    Cipher* cipher = factory.createCipher("Caesar");

    if (cipher) {
        encryptFile("input.txt", "encrypted.txt", cipher);
        decryptFile("encrypted.txt", "decrypted.txt", cipher);
        delete cipher;
    } else {
        std::cerr << "Cipher not found!" << std::endl;
    }

    return 0;
}
