#!/bin/bash

# Kompilacja programu
g++ -std=c++11 -o program.exe rozklad_na_czynniki_3.cpp

if [ $? -eq 0 ]; then
    if [ $# -gt 0 ]; 
    then 
        # Uruchomienie programu
        ./program.exe "$@"
        echo "Program został uruchomiony."
    else
        echo "Nieprawidłowa ilość argumentów." 
    fi
else
    echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji."
fi