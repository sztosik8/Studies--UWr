#ifndef KOLEJKA_H
#define KOLEJKA_H
#include <iostream>
#include <initializer_list>
using namespace std;

class Kolejka
{
private:
    int pojemnosc;
    int poczatek = 0;
    int ile = 0;
    string *tab;

public:
    Kolejka();
    Kolejka(int pojemnosc);
    Kolejka(initializer_list<string> lst);

    Kolejka(const Kolejka &other); // Konstruktor kopiujący
    Kolejka(Kolejka &&other);      // Konstruktor przenoszący

    const Kolejka &operator=(const Kolejka &other); // Operator przypisania kopiującego
    const Kolejka &operator=(Kolejka &&other);      // Operator przypisania przenoszącego
    ~Kolejka();

    void wstaw(string);
    string usun();
    string zprzodu();
    int dlugosc();
};
#endif