// Katarzyna Trzos
// lista 6 zadnanie 1
// sprawdzanie czy liczba jest palindromem
// wypisanie palindromu lub slowa odwrotnego
#include <stdio.h>
#include "operacje.h"
#include <stdlib.h>

int main()
{
    char c = getchar();

    while (c)
    {
        char *string = (char *)malloc(1005 * sizeof(char));
        char *koniec = string;

        while (c != ' ' && c != '\n')
        {
            *koniec = c;
            koniec++;
            c = getchar();
        }

        *koniec = '\0';

        char *s = string;
        char *k = koniec; // w indeksie k znajduje sie znak pusty

        if (palindrom(s) == 1)
        {
            printf("PALINDROM : ");
            while (s < k)
            {
                putchar(*s);
                s++;
            }
            printf("\n");
        }
        else
        {
            revers(s);

            printf("REWERS : ");
            while (s <= k) // wypisanie liter o indeksach <s,k>
            {
                putchar(*s);
                s++;
            }
            printf("\n");
        }
        c = getchar();
    }
    return 0;
}