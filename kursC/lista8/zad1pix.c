#include <stdio.h>
#include <stdlib.h>

FILE *plik;

int traktor(float imag, float rel, float cr, float ci)
{
    for (int i = 0; i < 200; i++)
    {
        float rel1 = rel;
        rel = (rel * rel) - (imag * imag);
        rel-=3;
        imag = (rel1 * imag) + (rel1 * imag);
        
    }
    if ((rel * rel) + (imag * imag) < 10)
    {
        return 1;
    }
    else
        return 0;
}

void nawza(float x, float y, float cr, float ci)
{
    for (float i = 1; i >= -1; i -= y) // urojone
    {
        for (float j = 1; j >= -1; j -= x) // rzeczywiste
        {
            if (traktor(i, j, cr, ci) == 1)
            {
                fprintf(plik, " 200 190 130 ");
            }
            else
            {
                fprintf(plik, " 70 130 80 ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{

    // printf("%d\n", argc);
    int n, m;
    float cr, ci;
    if (argc < 2)
    {
        n = 40;
        m = 25;
    }
    else
    {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    if (argc > 4)
    {
        cr = atof(argv[3]);
        ci = atof(argv[4]);
    }
    else
    {
        cr = 0.2;
        ci = 0.75;
    }

    plik = fopen("output.ppm", "w+");
    fprintf(plik, "P3\n%d %d\n255\n", n, m);

    float x = 2.0 / (n);
    float y = 2.0 / (m);
    // printf("%f\n", x);
    // printf("%f\n", y);

    nawza(x, y, cr, ci);

    return 0;
}