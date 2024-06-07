//
// Created by bog on 07.06.2024.
//

#include "CipherPrototypeFactory.h"

CipherPrototypeFactory::CipherPrototypeFactory() {}

CipherPrototypeFactory::~CipherPrototypeFactory() {
    for (auto& pair : prototypes) {
        delete pair.second;
    }
}

void CipherPrototypeFactory::registerCipher(const std::string& name, Cipher* prototype) {
    prototypes[name] = prototype;
}

Cipher* CipherPrototypeFactory::createCipher(const std::string& name) {
    return prototypes.count(name) ? prototypes[name]->clone() : nullptr;
}
