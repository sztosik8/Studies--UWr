#include <stdio.h>
#include <stdlib.h>
#include "operacje.h"

int main()
{
    char *string = (char *)malloc(1000 * sizeof(char));
    char *koniec = string;
    char c = getchar();

    while (c != ' ' && c != '\n')
    {
        *koniec = c;
        koniec++;
        c = getchar();
    }
    *koniec = '\0';

    char *s = string;
    char *k = koniec - 1;
    // printf("%c, %c \n", *(s), *(k));

    // while (s <= (k))
    // {
    //     putchar(*s);
    //     s++;
    // }
    // printf(" \n");

    char pomoc;
    // printf("%d, %d, \n", (s), (k));

    while (s <= k)
    {
        printf("%d, %d, \n", (s), (k));
        printf("%c, %c, \n", *(s), *(k));
        pomoc = *k;
        *k = *s;
        *s = pomoc;

        printf("%c, %c, \n", *(s), *(k));
        printf("\n");

        s++;
        k--;
    }

    // char *pomoc2s = string;
    // char *pomoc2k = koniec;

    // printf("REWERS : ");

    // while (pomoc2s <= pomoc2k)
    // {
    //     putchar(*pomoc2s);
    //     pomoc2s++;
    // }
    // printf("\n");

    ///// palindrom
    // while (s <= (k))
    // {
    //     printf("%c, %c \n", *(s), *(k));

    //     if (*s != *k)
    //     {
    //         printf("nie");
    //     }
    //     s++;
    //     k--;
    // }

    // printf("%c, %c \n", *(s), *(k-1));

    return 0;
}
