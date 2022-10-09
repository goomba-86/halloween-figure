#!/bin/bash

if [[ ! -d ./test-build ]] 
then
    mkdir test-build
fi
g++ -Wall -std=c++17 tests/tests.cpp -o ./test-build/tests -lgtest -lgtest_main -pthread
./test-build/tests
