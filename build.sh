#!/bin/bash

if [[ ! -d ./build ]] 
then
    mkdir build
fi
arm-linux-gnueabi-g++ -Wall -std=c++17 *.cpp -o ./build/halloween-robot
