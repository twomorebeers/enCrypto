#cmake_minimum_required(VERSION 3.28)
#project(FileEncryptor)
#
#set(CMAKE_CXX_STANDARD 17)
#
#add_executable(FileEncryptor main.cpp
#        src/main.cpp
#        src/CaesarCipher.cpp
#        src/CipherPrototypeFactory.cpp
#        include/CaesarCipher.h
#        include/Cipher.h
#        include/CipherPrototypeFactory.h)

cmake_minimum_required(VERSION 3.10)
project(FileEncryptor)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(FileEncryptor
        src/main.cpp
        src/CaesarCipher.cpp
        src/CipherPrototypeFactory.cpp
)
