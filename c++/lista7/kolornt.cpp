#include "kolornt.h++"
#include "kolortransparentny.h++"
#include "kolornazwany.h++"

kolornt::kolornt() : kolor_nazwany ::kolor_nazwany(), kolor_transparentny::kolor_transparentny() {}

kolornt::kolornt(int r, int g, int b, string n, int a) : kolor_nazwany ::kolor_nazwany(r, g, b, n), kolor_transparentny::kolor_transparentny(r, g, b, a) {}