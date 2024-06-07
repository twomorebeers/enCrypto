//
// Created by bog on 07.06.2024.
//

#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(int shift) : shift(shift) {}

std::string CaesarCipher::encrypt(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            result += static_cast<char>((c - offset + shift) % 26 + offset);
        } else {
            result += c;
        }
    }
    return result;
}

std::string CaesarCipher::decrypt(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            result += static_cast<char>((c - offset - shift + 26) % 26 + offset);
        } else {
            result += c;
        }
    }
    return result;
}

Cipher* CaesarCipher::clone() const {
    return new CaesarCipher(*this);
}
