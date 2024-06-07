#include <iostream>
#include <fstream>
#include <string>
#include "CipherPrototypeFactory.h"
#include "CaesarCipher.h"

void printAsciiArt() {
    std::cout << "         _            _              _             _    _        _          _        _            _       " << std::endl;
    std::cout << "        /\\ \\         /\\ \\     _    /\\ \\           /\\ \\ /\\ \\     /\\_\\       /\\ \\     /\\ \\         /\\ \\     " << std::endl;
    std::cout << "       /  \\ \\       /  \\ \\   /\\_\\ /  \\ \\         /  \\ \\\\ \\ \\   / / /      /  \\ \\    \\_\\ \\       /  \\ \\    " << std::endl;
    std::cout << "      / /\\ \\ \\     / /\\ \\ \\_/ / // /\\ \\ \\       / /\\ \\ \\\\ \\ \\_/ / /      / /\\ \\ \\   /\\__ \\     / /\\ \\ \\   " << std::endl;
    std::cout << "     / / /\\ \\_\\   / / /\\ \\___/ // / /\\ \\ \\     / / /\\ \\_\\\\ \\___/ /      / / /\\ \\_\\ / /_ \\ \\   / / /\\ \\ \\  " << std::endl;
    std::cout << "    / /_/_ \\/_/  / / /  \\/____// / /  \\ \\_\\   / / /_/ / / \\ \\ \\_/      / / /_/ / // / /\\ \\ \\ / / /  \\ \\_\\ " << std::endl;
    std::cout << "   / /____/\\    / / /    / / // / /    \\/_/  / / /__\\/ /   \\ \\ \\      / / /__\\/ // / /  \\/_// / /   / / / " << std::endl;
    std::cout << "  / /\\____\\/   / / /    / / // / /          / / /_____/     \\ \\ \\    / / /_____// / /      / / /   / / /  " << std::endl;
    std::cout << " / / /______  / / /    / / // / /________  / / /\\ \\ \\        \\ \\ \\  / / /      / / /      / / /___/ / /   " << std::endl;
    std::cout << "/ / /_______\\/ / /    / / // / /_________\\/ / /  \\ \\ \\        \\ \\_\\/ / /      /_/ /      / / /____\\/ /    " << std::endl;
    std::cout << "\\/__________/\\/ /     \\_/_ \\/____________/\\/_/    \\_\\/         \\/_/\\/_/       \\_\\/       \\/_________/     " << std::endl;
    std::cout << "                                                                                                          " << std::endl;
}

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

    std::cout<<std::endl;

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
    printAsciiArt();

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

