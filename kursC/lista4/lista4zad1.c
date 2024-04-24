// Katarzyna Trzos
// Lista 4 zadanie 1
#include <stdio.h>

typedef unsigned short data;

char *dnityg[] = {"pon", "wto", "sro", "czwa", "pia", "sob", "nie"};
char *miesiac[] = {"stycznia", "lutego", "marca", "kwietnia", "maja", "czerwca", "lipca", "sierpnia", "wrzesnia", "pazdziernika", "lisopada", "grudzien"};
char *zwierze[] = {"malpy(1)", "koguta(2)", "swini(3)", "szczura(4)", "tygrysa(5)", "krolika(6)", "smoka(7)", "weza(8)", "konia(9)", "owcy(10)", "kozy(11)", "psa(12)"};

int bladdaty(data liczba)
{
    if (((liczba >> 3) & 31) == 31)
    {
        liczba = liczba >> 5;
        if ((liczba & 15) - 1 == 3 || (liczba & 15) - 1 == 5 || (liczba & 15) - 1 == 8 || (liczba & 15) - 1 == 10)
        {
            return 1;
        }
    }
    if (((liczba >> 3) & 31) > 29)
    {
        if ((liczba & 15) - 1 == 1)
        {
            return 1;
        }
    }
    return 0;
}

void wypiszdata(data liczba)
{
    printf("%s, ", dnityg[(liczba & 7) - 1]); // dzien
    liczba = liczba >> 3;

    if (liczba & 31)
        printf("%d ", liczba & 31); // dzien miesiaca
    liczba = liczba >> 5;

    printf("%s, ", miesiac[(liczba & 15) - 1]); // miesiac
    liczba = liczba >> 4;

    printf("rok %s \n", zwierze[(liczba & 15) - 1]); // zwierze
}

int main()
{
    data liczba;
    scanf("%hd", &liczba);

    while (liczba != 0 || feof(stdin))
    {
        bladdaty(liczba);
        if (bladdaty(liczba) == 0)      
            wypiszdata(liczba);
        scanf("%hd", &liczba);
    }

    return 0;
}