#pragma once
#include "kolor.h++"
#include <iostream>
#include <stdexcept>

class kolor_transparentny : virtual private kolor
{
protected:
    int alfa;

public:
    kolor_transparentny();
    kolor_transparentny(int r, int g, int b, int a);
    int get_alfa();
};