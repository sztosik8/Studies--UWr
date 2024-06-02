#pragma once
#include "kolornazwany.h++"
#include "kolortransparentny.h++"
#include <iostream>
#include <stdexcept>

class kolornt : public kolor_nazwany, public kolor_transparentny
{
public:
    kolornt();
    kolornt(int r, int g, int b, string n, int a);
};