#!/bin/bash

if [[ ! -d ./build ]] 
then
    mkdir build
fi
arm-linux-gnueabi-g++ -Wall -std=c++17 main.cpp gpio-controller-impl.cpp file-io-impl.cpp -o ./build/halloween-robot
