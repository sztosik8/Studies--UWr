#!/bin/bash

# Kompilacja programu
g++ -std=c++11 -o program.exe rzymskie.cpp

if [ $? -eq 0 ]
then
    if [ $# == 3 ]
    then 
        # Uruchomienie programu
        ./program.exe $1 $2 $3
        echo "Program został uruchomiony."
    else
        echo "Nieprawidłowa ilość argumentów." 
    fi
     
else
    echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji."
fi