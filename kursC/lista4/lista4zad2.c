
// Katarzyna Trzos
// Lista 3 zadanie 1
// liczenie zagniezdzenia { }

#include <stdio.h>

int zagn = 0;

void liczbanaw(char znak)
{
    while (znak != EOF && zagn >= 0)
    {
        // • Po kazdym nawiasie otwierajacym wstawiamy znak konca wiersza i ak-
        // tualizujemy biezacy poziom zagniezdzenia.
        if (znak == '{')
        {
            printf("\n");
            zagn++;
        }
        // Kazdy wiersz wypisujemy wciety o 4*zagniezdzenie spacji na poczatku
        // wiersza (w tym celu pomijamy wszystkie spacje na poczatku wiersza
        // wejsciowego i wypisujemy tyle spacji ile trzeba).
        else if (znak == '\n')
        {
            znak = getchar();
            printf("\n");

            while (znak == ' ')
            {
                znak = getchar();
            }

            for (int i = 0; i < zagn * 4; i++)
            {
                printf(" ");
            }
        }

        // Nawias zamykajacy jest wypisywany w osobnym wierszu weiety o cztery
        // spacje mniej nizwskazuje zagniezdzenie na poczatku wiersza
        else if (znak == ']')
        {
            printf("zad \n");
            for (int i = 0; i < (zagn - 4); i++)
            {
                printf(" ");
            }
            printf("%c",'}');

            zagn--;
        }
        else
        {
            printf("%c",znak);

        }
        znak=getchar();
        // Da nawiasow zamykajacych cialo funkcji dopisujemy po nim komentarz
        // zawierajacy "deklaracje" funkcji. Zakladamy ze miesci sie ona na wejsciu
        // w jednym wierszu, dopuszczamy jednak ze na wejsciu nawias otwierajacy
        // ciao funkcji jest w nastepnym wierszu.

    }
    return;
}

int main()
{
    char znak;
    znak = getchar();
    liczbanaw(znak);

    printf("\n");

    return 0;
}