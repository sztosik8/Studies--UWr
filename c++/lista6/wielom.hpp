#ifndef WIELOM_H
#define WIELOM_H
#include <iostream>
#include <initializer_list>
using namespace std;

class wielom
{
private:
    int n;
    double *a;

public:
    //wielom();
    wielom(int st=0, double wsp=1.0);           // konstruktor jednomianu
    wielom(int st, const double wsp[]);   // konstruktor wielomianu
    wielom(initializer_list<double> wsp); // lista współczynników
    wielom(const wielom &w);              // konstruktor kopiujący
    wielom(wielom &&w);                   // konstruktor przenoszący
    wielom &operator=(const wielom &w);   // przypisanie kopiujące
    wielom &operator=(wielom &&w);        // przypisanie przenoszące
    ~wielom();                            // destruktor

    int stopien() const;
    double operator()(double x) const; // wartość wielomianu dla x
    double operator[](int i) const;    // do odczytu współczynnika
    double &operator[](int i);         // do zapisu współczynnika

    friend istream &operator>>(istream &we, wielom &w);
    friend ostream &operator<<(ostream &wy, const wielom &w);

    friend wielom operator+(const wielom &u, const wielom &v);
    friend wielom operator-(const wielom &u, const wielom &v);
    friend wielom operator*(const wielom &u, const wielom &v);
    friend wielom operator*(const wielom &u, double c);

    wielom &operator+=(const wielom &v);
    wielom &operator-=(const wielom &v);
    wielom &operator*=(const wielom &v);
    wielom &operator*=(double c);

private:
    double calcValue(double x) const;
};
#endif