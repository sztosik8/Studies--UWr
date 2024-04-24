#!/bin/bash

# Kompilacja programu

g++ -std=c++11 -o output.exe lista1.cpp
# Sprawdzenie czy kompilacja zakończyła się sukcesem
if [ $? -eq 0 ]; then
    echo "Kompilacja zakończona sukcesem."
    # Uruchomienie programu
    ./output.exe < dane.txt > wyniki.txt
else
    echo "Błąd podczas kompilacji. Program nie zostanie uruchomiony."
fi
