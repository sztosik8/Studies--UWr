#include "kolornazwany.h++"

kolor_nazwany::kolor_nazwany() : kolor::kolor()
{
    this->nazwa = "";
}

kolor_nazwany::kolor_nazwany(int r, int g, int b, string n) : kolor::kolor(r, g, b)
{
    this->nazwa = n;
}