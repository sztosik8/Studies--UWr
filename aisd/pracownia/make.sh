#!/bin/bash

# Kompilacja programu

g++ trojkaty.cpp

if [ $? -eq 0 ]; then
    # Uruchomienie programu
    ./a.out
    echo "Program został uruchomiony."
else
    echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji."
fi