// Kataryzna Trzos
// Lista 8 zadanie 1

#include <stdio.h>
#include <stdlib.h>

int traktor(float imag, float rel, float cr, float cu);
void wypisanie(float x, float y, float cr, float cu);

int main(int argc, char *argv[])
{

    int n = 40;
    int m = 25;

    float c_rz = 0.2;
    float c_ur = 0.75;

    if (argc > 1)
    {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
        if (argc > 3)
        {
            c_rz = atof(argv[4]);
            c_ur = atof(argv[5]);
        }
    }

    float x = 2.0 / (n);
    float y = 2.0 / (m);

    wypisanie(x, y, c_rz, c_ur);
    return 0;
}

int traktor(float imag, float rel, float cr, float cu)
{
    for (int i = 0; i < 200; i++)
    {
        float rel1 = rel;
        rel = (rel * rel) - (imag * imag) - cr;
        imag = (rel1 * imag) + (rel1 * imag) - cu;
    }
    if ((rel * rel) + (imag * imag) < 4)
       return 1;
    else
        return 0;
}

void wypisanie(float x, float y, float cr, float cu)
{
    for (float i = 1; i >= -1; i -= y) // urojone
    {
        for (float j = 1; j >= -1; j -= x) // rzeczywiste
        {
            if (traktor(i, j, cr, cu) == 1) // sprawdzenie czy liczba nalezy do atraktora
                printf("O");
            else
                printf("  ");
        }
        printf("\n");
    }
}