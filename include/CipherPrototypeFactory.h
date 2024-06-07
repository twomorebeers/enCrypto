////
//// Created by bog on 07.06.2024.
////
//
//#ifndef FILEENCRYPTOR_CIPHERPROTOTYPEFACTORY_H
//#define FILEENCRYPTOR_CIPHERPROTOTYPEFACTORY_H
//
//#endif //FILEENCRYPTOR_CIPHERPROTOTYPEFACTORY_H

#ifndef CIPHERPROTOTYPEFACTORY_H
#define CIPHERPROTOTYPEFACTORY_H

#include "Cipher.h"
#include <unordered_map>
#include <string>

class CipherPrototypeFactory {
public:
    CipherPrototypeFactory();
    ~CipherPrototypeFactory();

    void registerCipher(const std::string& name, Cipher* prototype);
    Cipher* createCipher(const std::string& name);

private:
    std::unordered_map<std::string, Cipher*> prototypes;
};

#endif // CIPHERPROTOTYPEFACTORY_H
