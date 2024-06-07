#include <iostream>
#include <fstream>
#include <string>
#include "CipherPrototypeFactory.h"
#include "CaesarCipher.h"

void encryptFile(const std::string& inputFile, const std::string& outputFile, Cipher* cipher) {
    std::ifstream in(inputFile);
    if (!in.is_open()) {
        std::cerr << "Failed to open input file: " << inputFile << std::endl;
        return;
    }

    std::ofstream out(outputFile);
    if (!out.is_open()) {
        std::cerr << "Failed to open output file: " << outputFile << std::endl;
        in.close();
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::string encryptedLine = cipher->encrypt(line);
        out << encryptedLine << '\n';
        std::cout << "Encrypted: " << encryptedLine << std::endl;
    }
    in.close();
    out.close();
}

void decryptFile(const std::string& inputFile, const std::string& outputFile, Cipher* cipher) {
    std::ifstream in(inputFile);
    if (!in.is_open()) {
        std::cerr << "Failed to open input file: " << inputFile << std::endl;
        return;
    }

    std::ofstream out(outputFile);
    if (!out.is_open()) {
        std::cerr << "Failed to open output file: " << outputFile << std::endl;
        in.close();
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::string decryptedLine = cipher->decrypt(line);
        out << decryptedLine << '\n';
        std::cout << "Decrypted: " << decryptedLine << std::endl;
    }
    in.close();
    out.close();
}

int main() {
    std::cout << "Starting encryption program..." << std::endl;

    CipherPrototypeFactory factory;
    factory.registerCipher("Caesar", new CaesarCipher(5));

    Cipher* cipher = factory.createCipher("Caesar");

    if (cipher) {
        std::cout << "Encrypting file..." << std::endl;
        encryptFile("input.txt", "encrypted.txt", cipher);

        std::cout << "Decrypting file..." << std::endl;
        decryptFile("encrypted.txt", "decrypted.txt", cipher);

        delete cipher;
    } else {
        std::cerr << "Cipher not found!" << std::endl;
    }

    std::cout << "Encryption program finished." << std::endl;
    return 0;
}
