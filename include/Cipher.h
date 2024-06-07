////
//// Created by bog on 07.06.2024.
////
//
//#ifndef FILEENCRYPTOR_CIPHER_H
//#define FILEENCRYPTOR_CIPHER_H
//
//#endif //FILEENCRYPTOR_CIPHER_H

#ifndef CIPHER_H
#define CIPHER_H

#include <string>

class Cipher {
public:
    virtual ~Cipher() = default;
    virtual std::string encrypt(const std::string& text) = 0;
    virtual std::string decrypt(const std::string& text) = 0;
    virtual Cipher* clone() const = 0;
};

#endif // CIPHER_H
