#!/bin/bash

g++ -std=c++17 -c *.cpp
g++ -std=c++17 *.o -o main

if [ $? -eq 0 ]; then

    ./main
    echo "The program has been executed."
    
else
    echo "Compilation of source files failed. Check the compilation errors."
fi
