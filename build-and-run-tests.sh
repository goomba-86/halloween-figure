#!/bin/bash

if [[ ! -d ./test-build ]] 
then
    mkdir test-build
fi
g++ -Wall -I. -std=c++17 gpio-controller-impl.cpp tests/*.cpp -o ./test-build/tests -lgtest -lgtest_main -lgmock -pthread
./test-build/tests
