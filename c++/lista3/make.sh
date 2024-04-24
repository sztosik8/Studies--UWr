#!/bin/bash

# Kompilacja programu

g++ -c classes.cpp -o classes.o
g++ -c functions.cpp -o functions.o
g++ -c main.cpp -o main.o
g++ classes.o functions.o main.o -o figury_na_plaszczyznie

if [ $? -eq 0 ]; then
    # Uruchomienie programu
    ./figury_na_plaszczyznie
    echo "Program został uruchomiony."
else
    echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji."
fi
