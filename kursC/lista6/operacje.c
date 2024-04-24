#include "operacje.h"
#include <stdio.h>

int palindrom(char *s)
{
    char *k = s;
    while (*k != '\0') // liczy indeks ostatniej litery
        k++;
    k--;

    while (s < k)
    {
        if (*s != *k) // sprawdza czy litery o indeksach s i k sa rowne
            return 0; // nie jest palindrom
        s++;
        k--; 
    }
    return 1; // jest palindrom
}

void revers(char *s)
{
    char *k = s;

    while (*k != '\0') // liczy indeks ostatniej litery
        k++;
    k--;

    char pomoc;
    while (s <= k) // zamienia miejscami litery o indeksach s i k
    {
        pomoc = *k;
        *k = *s;
        *s = pomoc;

        s++;
        k--;
    }
    return;
}