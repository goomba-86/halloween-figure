#!/bin/bash

if [[ ! -d ./build ]] 
then
    mkdir build
fi
arm-linux-gnueabi-g++ main.cpp -o ./build/halloween-robot
