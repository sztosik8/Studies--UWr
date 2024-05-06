#pragma once
#include "kolornazwany.h++"
#include "kolortransparentny.h++"
#include <iostream>
#include <stdexcept>

class kolornt : kolor_nazwany, kolor_transparentny
{
public:
    kolornt();
    kolornt(int r, int g, int b, string n, int a);
};