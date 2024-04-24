#include <stdio.h>

void silniowarep(int n)
{
    int silnia = 1;
    int liczba = 0;

    while (silnia <= n)
    {
        liczba++;
        silnia *= liczba;

        // printf("%d \n", silnia);
    }

    silnia /= liczba;
    liczba--;

    while (liczba > 0)
    {
        if (silnia <= n)
        {
            printf("%d ", n / silnia);
            n %= silnia;
        }
        else
        {
            printf("%d ", 0);
        }
        liczba--;
        silnia /= liczba;
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    silniowarep(n);

    return 0;
}