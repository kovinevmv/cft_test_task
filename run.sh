#!/bin/bash

./clean.sh
mkdir build
cd build 
cmake -D BUILD_TESTS=ON ..
make
./tests
