/*
 * Katrzyna Trzos
 * Lista 1 zadanie 2
 * gcc zad2.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nom;
    int denom;
} Ulamek;

Ulamek *nowy_ulamek(int nom, int denom);

void skroc(Ulamek *u);
void show(Ulamek *u); // funkcja wypisuje ulamki nie wylaczajac calosci
void show_int(Ulamek *u); // funkcja zamienia ulamki niewlasniwe i wypisuje czesc calkowita wraz ze skroconym ulamkiem

// dopisek _ptr oznacza ze funkcje zwracaja pointer na nowy ulamek
Ulamek *dodaj_ptr(Ulamek *u1, Ulamek *u2);
Ulamek *odejmij_ptr(Ulamek *u1, Ulamek *u2);
Ulamek *pomnoz_ptr(Ulamek *u1, Ulamek *u2);
Ulamek *podziel_ptr(Ulamek *u1, Ulamek *u2);

// dopisek _mod_sec oznacza funkcje ktore modyfikuja drugi argument
void dodaj_mod_sec(Ulamek *u1, Ulamek *u2);
void odejmij_mod_sec(Ulamek *u1, Ulamek *u2);
void pomnoz_mod_sec(Ulamek *u1, Ulamek *u2);
void podziel_mod_sec(Ulamek *u1, Ulamek *u2);

int main()
{
    Ulamek *u1 = nowy_ulamek(1, 2);
    Ulamek *u2 = nowy_ulamek(6, 3);
    Ulamek *u3 = nowy_ulamek(-4, 3);
    Ulamek *u4 = nowy_ulamek(1, -6);
    Ulamek *u5 = nowy_ulamek(1, -6);
    Ulamek *u6 = nowy_ulamek(-4, 0);

        //** TESTY **//

    // printf("\n ulamki wypisane funkcja show():\n");
    // show(u1);
    // show(u2);
    // show(u3);
    // show(u4);
    // show(u6);

    // printf("\n te same ulamki wypisane funkcja show_int():\n");
    // show_int(u1);
    // show_int(u2);
    // show_int(u3);
    // show_int(u4);
    // show_int(u6);

    // printf("\n dodawanie :\n");
    // show(u1);
    // printf("+\n");
    // show(u2);
    // printf("=\n");
    // show(dodaj_ptr(u1, u2));

    // printf("\n");
    // show(u3);
    // printf("+\n");
    // show(u4);
    // printf("=\n");
    // show(dodaj_ptr(u3, u4));

    // printf("\n odejmowanie :\n");
    // show(u1);
    // printf("-\n");
    // show(u2);
    // printf("=\n");
    // show(odejmij_ptr(u1, u2));

    // printf("\n");
    // show(u5);
    // printf("-\n");
    // show(u4);
    // printf("=\n");
    // show(odejmij_ptr(u5, u4));

    // printf("\n mnozenie :\n");
    // show(u1);
    // printf("*\n");
    // show(u2);
    // printf("=\n");
    // show(pomnoz_ptr(u1, u2));

    // printf("\n");
    // show(u3);
    // printf("*\n");
    // show(u4);
    // printf("=\n");
    // show(pomnoz_ptr(u3, u4));

    // printf("\n dzielenie :\n");
    // show(u1);
    // printf("/\n");
    // show(u2);
    // printf("=\n");
    // show(podziel_ptr(u1, u2));

    // printf("\n");
    // show(u3);
    // printf("/\n");
    // show(u4);
    // printf("=\n");
    // show(podziel_ptr(u3, u4));

    // printf("\n dodawanie ze zmiana drugiego skladnika :\n");
    // show(u1);
    // printf("+\n");
    // show(u2);
    // printf("=\n");
    // dodaj_mod_sec(u1, u2);
    // show(u2);

    // printf("\n");
    // show(u3);
    // printf("+\n");
    // show(u4);
    // printf("=\n");
    // dodaj_mod_sec(u3, u4);
    // show(u4);

    // printf("\n odejmowanie ze zmiana drugiego skladnika :\n");
    // show(u1);
    // printf("-\n");
    // show(u2);
    // printf("=\n");
    // odejmij_mod_sec(u1, u2);
    // show(u2);

    // printf("\n");
    // show(u3);
    // printf("-\n");
    // show(u4);
    // printf("=\n");
    // odejmij_mod_sec(u3, u4);
    // show(u4);
    
    // printf("\n mnozenie ze zmiana drugiego skladnika :\n");
    // show(u1);
    // printf("*\n");
    // show(u2);
    // printf("=\n");
    // pomnoz_mod_sec(u1, u2);
    // show(u2);

    // printf("\n");
    // show(u3);
    // printf("*\n");
    // show(u4);
    // printf("=\n");
    // pomnoz_mod_sec(u3, u4);
    // show(u4);

    // printf("\n dzielenie ze zmiana drugiego skladnika :\n");
    // show(u1);
    // printf("/\n");
    // show(u2);
    // printf("=\n");
    // podziel_mod_sec(u1, u2);
    // show(u2);

    // printf("\n");
    // show(u3);
    // printf("/\n");
    // show(u4);
    // printf("=\n");
    // podziel_mod_sec(u3, u4);
    // show(u4);

    return 0;
}

Ulamek *nowy_ulamek(int nom, int denom)
{
    Ulamek *u = malloc(sizeof(Ulamek));
    u->nom = nom;
    u->denom = denom;
    skroc(u);
    return u;
}
void skroc(Ulamek *u)
{
    int a = u->nom;
    int b = u->denom;
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    u->nom /= a;
    u->denom /= a;
}

void show(Ulamek *u)
{
    int a = u->nom;
    int b = u->denom;
    if (b == 0)
    {
        // funkcja show() nie wypisuje ulamkow ktore maja 0 w manowniku, zwraca informacje o niepoprawnym ulamku
        printf("niepoprawny umalek\n");
        return;
    }
    if(a==0)
    {
        printf("0\n");
        return;
    }

    if (a * b < 0) // jesli ulamek jest mniejszy od zera jest wypisywany w postaci -(a/b)
    {

        printf("-(%d/%d)\n", abs(a), abs(b));
    }
    else // w przeciwny wypadku a/b
        printf("%d/%d\n", a, b);
}

void show_int(Ulamek *u)
{
    int a = u->nom;
    int b = u->denom;
    if (b == 0)
    {
        // funkcja show_int() nie wypisuje ulamkow ktore maja 0 w manowniku, zwraca informacje o niepoprawnym ulamku
        printf("niepoprawny umalek\n");
        return;
    }

    if (abs(a) >= abs(b))
    {
        printf("%d ", (a / b));
        a -= (a / b)*b;
        if (a == 0)
            printf("\n");
        
        else
        {
            Ulamek *v = nowy_ulamek(abs(a), abs(b));
            show(v);
        }
    }
    else
        show(u);
}

Ulamek *dodaj_ptr(Ulamek *u1, Ulamek *u2)
{
    int a = (u1->nom * u2->denom) + (u1->denom * u2->nom);
    int b = ((u1->denom * u2->denom));

    Ulamek *u = nowy_ulamek(a, b);
    return u;
}
Ulamek *odejmij_ptr(Ulamek *u1, Ulamek *u2)
{
    int a = (u1->nom * u2->denom) - (u1->denom * u2->nom);
    int b = ((u1->denom * u2->denom));

    Ulamek *u = nowy_ulamek(a, b);
    return u;
}

Ulamek *pomnoz_ptr(Ulamek *u1, Ulamek *u2)
{
    int a = (u1->nom * u2->nom);
    int b = ((u1->denom * u2->denom));

    Ulamek *u = nowy_ulamek(a, b);
    return u;
}
Ulamek *podziel_ptr(Ulamek *u1, Ulamek *u2)
{
    int a = (u1->nom * u2->denom);
    int b = ((u1->denom * u2->nom));

    Ulamek *u = nowy_ulamek(a, b);
    return u;
}

void dodaj_mod_sec(Ulamek *u1, Ulamek *u2)
{
    int a = (u1->nom * u2->denom) + (u1->denom * u2->nom);

    u2->nom = a;
    u2->denom *= u1->denom;
    skroc(u2);
}

void odejmij_mod_sec(Ulamek *u1, Ulamek *u2)
{
    int a = (u1->nom * u2->denom) - (u1->denom * u2->nom);

    u2->nom = a;
    u2->denom *= u1->denom;
    skroc(u2);
}
void pomnoz_mod_sec(Ulamek *u1, Ulamek *u2)
{
    u2->nom *= u1->nom;
    u2->denom *= u1->denom;
    skroc(u2);
}
void podziel_mod_sec(Ulamek *u1, Ulamek *u2)
{
    int a = (u1->nom * u2->denom);
    int b = ((u1->denom * u2->nom));

    u2->nom = a;
    u2->denom = b;
    skroc(u2);
}
