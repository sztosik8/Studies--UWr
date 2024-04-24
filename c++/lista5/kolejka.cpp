#ifndef KOLEJKA_CPP
#include "kolejka.hpp"
#include <iostream>

using namespace std;

Kolejka::Kolejka()
{
    pojemnosc = 1;
    tab = new string[pojemnosc];
}

Kolejka::Kolejka(int poj)
{
    if (poj <= 0)
    {
        throw invalid_argument("pojemnosc kolejki musi byc dodatnia ");
    }
    else
    {
        pojemnosc = poj;
        tab = new string[pojemnosc];
    }
}

Kolejka::Kolejka(std::initializer_list<std::string> lst)
{
    int n = lst.size();
    pojemnosc = n;
    tab = new string[n];
    ile = 0;

    for (auto x : lst)
    {
        tab[ile] = x;
        ile++;
    }
}

Kolejka::Kolejka(const Kolejka &other)
{
    pojemnosc = other.pojemnosc;
    poczatek = other.poczatek;
    ile = other.ile;
    tab = new string[other.pojemnosc];
    for (int i = 0; i < other.ile; ++i)
    {
        tab[i] = other.tab[i];
    }
}

Kolejka::Kolejka(Kolejka &&other) : Kolejka()
{

    swap(pojemnosc, other.pojemnosc);
    swap(tab, other.tab);
    swap(poczatek, other.poczatek);
    swap(ile, other.ile);
}

const Kolejka &Kolejka::operator=(const Kolejka &other) // kopiowanie
{
    if (this != &other)
    {
        this->~Kolejka();
        pojemnosc = other.pojemnosc;
        poczatek = other.poczatek;
        ile = other.ile;
        tab = new string[other.pojemnosc];

        for (int i = 0; i < other.ile; ++i)
        {
            tab[i] = other.tab[i];
        }
    }
    return *this;
}

const Kolejka &Kolejka::operator=(Kolejka &&other)
{
    if (this != &other)
    {
        swap(pojemnosc, other.pojemnosc);
        swap(tab, other.tab);
        swap(poczatek, other.poczatek);
        swap(ile, other.ile);
    }

    return *this;
}

Kolejka::~Kolejka()
{
    delete[] tab;
}

void Kolejka::wstaw(string napis)
{
    if (ile + 1 > pojemnosc)
    {
        throw invalid_argument("nie mozna dodac elementu, kolejka jest pelna ");
    }
    else
    {
        int ind = (poczatek + ile) % pojemnosc;
        tab[ind] = napis;
        ile++;
    }
}

string Kolejka::usun()
{
    if (ile <= 0)
    {
        throw invalid_argument("nie mozna usunac elementu, kolejka jest pusta ");
    }
    else
    {
        string &top = tab[poczatek];
        poczatek = (poczatek + 1) % pojemnosc;
        ile--;
        return top;
    }
}

string Kolejka::zprzodu()
{
    if (ile <= 0 || tab == nullptr)
    {
        throw invalid_argument("kolejka jest pusta ");
    }

    else
    {
        return tab[poczatek];
    }
}
int Kolejka::dlugosc()
{
    return ile;
}

#endif