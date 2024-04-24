// Katarzyna Trzos
// Lista2 Zadanie1
// wczytywanie liczby w systemie baza
// wypisywanie jej w sysyemie dwojkowym, osemkowym i dziesietnm
// uzywajac funkcji getchar() i putchar()

#include <stdio.h>

void print_long(int value) // funkcja wypisujaca liczbe dziesietna uzywajac putchar
{
    if (value != 0)
    {
        print_long(value / 10);
        putchar((value % 10) + '0');
    }
}

int NumGet(int baza)
{
    int liczba = 0;
    char el;
    el = getchar();
    int i;

    while (el != '.')
    {
        if (0 <= el - '0' && el - '0' < baza)
        {
            liczba += el - '0';
            liczba *= 10;
            i++;
        }
        el = getchar();
    }
    liczba /= 10;
    return liczba;
}

void NumPut(int baza, int x)
{
    ////////////////// dziesietny//////////////////////////////
    int liczba10 = x;
    int potega = 1;
    int odp10 = 0;
    while (liczba10 > 0)
    {
        odp10 += (liczba10 % 10) * (potega);
        potega *= baza;
        liczba10 /= 10;
    }
    printf("Dziesietny: ");
    print_long(odp10);
    putchar('\n');

    int liczba8 = odp10; // zapisuje liczbe w systemie dziesietnym
    int liczba2 = odp10; // aby pozniej zamienic ja na dwojkowy i osemkowy

    /////////////////// dwojkowy//////////////////////////////

    potega = 1;
    printf("Dwojkowy: ");

    while (potega <= liczba2)
    {
        potega *= 2;
    }
    potega /= 2;
    while (liczba2 > 0)
    {
        if (potega <= liczba2)
        {
            putchar('1');
            liczba2 -= potega;
        }
        else
        {
            putchar('0');
        }
        potega /= 2;
    }
    putchar('\n');

    /////////////////////// osemkowy//////////////////////

    printf("Osemkowy: ");
    potega = 1;
    int ile = 0;

    while (potega <= liczba8)
    {
        potega *= 8;
    }
    potega /= 8;
    while (liczba8 > 0)
    {
        while (potega <= liczba8)
        {
            ile++;
            liczba8 -= potega;
        }
        printf("%d", ile);
        ile = 0;

        potega /= 8;
    }
    printf("\n");

    return;
}

int main()
{
    int baza;

    printf("podaj baze i ciag znakow zakonczony kropka: \n");

    scanf("%d", &baza);

    int x = NumGet(baza);
    printf("%d\n", x);

    NumPut(baza, x);

    return 0;
}