// Katarzyna Trzos
// Lista 5 zadanie 2
//
#include <stdio.h>

FILE *plik;

int pierwsze(int n)
{
    if (n < 2)
    {
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void spiralawiersz(int n, int k)
{
    int liczba;
    if (n % 2 == 0)
    {
        if (k == 1)
        {
            for (int i = 0; i < n; i++)
            {
                liczba = (n * n) - 3 * n + 3 + i;
                if (pierwsze(liczba) == 1) // jest pierwsza
                {
                    fprintf(plik, " 255  255  0 ");
                }
                else
                {
                    fprintf(plik, " 0  0  255 ");
                }
            }
        }
        else if (k == n)
        {
            for (int i = 0; i < n; i++)
            {
                liczba = (n * n) - i;
                if (pierwsze(liczba) == 1) // jest pierwsza
                {
                    fprintf(plik, " 255  255  0 ");
                }
                else
                {
                    fprintf(plik, " 0  0  255 ");
                }
            }
        }
        else
        {
            spiralawiersz(n - 1, k);
            liczba = n * n - 2 * n + k + 1;
            if (pierwsze(liczba) == 1) // jest pierwsza
            {
                fprintf(plik, " 255  255  0 ");
            }
            else
            {
                fprintf(plik, " 0  0  255 ");
            }
        }
    }
    if (n % 2 == 1)
    {
        if (k == 1)
        {
            for (int i = 0; i < n; i++)
            {
                liczba = (n * n) - n + 1 + i;
                if (pierwsze(liczba) == 1) // jest pierwsza
                {
                    fprintf(plik, " 255  255  0 ");
                }
                else
                {
                    fprintf(plik, " 0  0  255 ");
                }
            }
        }
        else if (k == n)
        {
            for (int i = 0; i < n; i++)
            {
                liczba = (n * n) - i + 2 - 2 * n;
                if (pierwsze(liczba) == 1) // jest pierwsza
                {
                    fprintf(plik, " 255  255  0 ");
                }
                else
                {
                    fprintf(plik, " 0  0  255 ");
                }
            }
        }
        else
        {
            liczba = n * n - n - k + 2;
            if (pierwsze(liczba) == 1) // jest pierwsza
            {
                fprintf(plik, " 255  255  0 ");
            }
            else
            {
                fprintf(plik, " 0  0  255 ");
            }
            spiralawiersz(n - 1, k - 1);
        }
    }
}

int main()
{

    int n;

    scanf("%d", &n);
    plik = fopen("output.ppm", "w+");
    fprintf(plik, "P3\n%d %d\n255\n", n, n);

    for (int i = 1; i <= n; i++)
    {
        spiralawiersz(n, i);
    }

    return 0;
}