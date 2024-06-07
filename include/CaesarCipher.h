////
//// Created by bog on 07.06.2024.
////
//
//#ifndef FILEENCRYPTOR_CAESARCIPHER_H
//#define FILEENCRYPTOR_CAESARCIPHER_H
//
//#endif //FILEENCRYPTOR_CAESARCIPHER_H

#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "Cipher.h"

class CaesarCipher : public Cipher {
public:
    explicit CaesarCipher(int shift);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    Cipher* clone() const override;

private:
    int shift;
};

#endif // CAESARCIPHER_H
