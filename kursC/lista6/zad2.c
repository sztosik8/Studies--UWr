// Katarzyna Trzos
// Lista 6 zadanie 2
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ksiazka
{
    char *autor;
    char *tytul;
    int rok_wyd;
    int liczba_str;
} tab[10000];

int main()
{

    char *autor = (char *)malloc(100 * sizeof(char));
    char *tytul = (char *)malloc(100 * sizeof(char));

    struct ksiazka pi;
    pi.tytul = "twojtato";
    pi.rok_wyd = 2030;
    pi.liczba_str = 1234;

    char c;
    c = getchar();

    for (int n = 0; c; n++)
    {
        c = getchar();
        // wczytaj autora

        // wczytaj tytul

        int x;
        scanf("%d", &x);
        tab[n].rok_wyd = x;

        scanf("%d", &x);
        tab[n].liczba_str = x;

        printf(" nr petli %d rok %d strony %d\n", n, tab[n].rok_wyd, tab[n].liczba_str);
        c = getchar(); //spacja
        c = getchar(); 
    }

    qsort(tab, tab+10, autor);

    return 0;
}