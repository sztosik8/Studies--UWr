#!/bin/bash
g++ -c *.cpp

if [ $? -eq 0 ]; then
    
    if [ $? -eq 0 ]; then

        ./main
        echo "The program has been executed."
    else
        echo "Compilation of the executable file failed. Check the compilation errors."
    fi
else
    echo "Compilation of source files failed. Check the compilation errors."
fi
