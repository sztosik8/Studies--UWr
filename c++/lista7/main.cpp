
#include "kolor.cpp"
#include "kolornazwany.cpp"
#include "kolortransparentny.cpp"
#include "piksel.cpp"
#include "pikselkolorowy.cpp"
#include "kolornt.cpp"

#include <iostream>
using namespace std;

int main()
{
    cout << "Testowanie klasy kolor" << '\n';

    kolor k1 = kolor();
    kolor k2 = kolor();
    kolor k3 = kolor();

    try
    {
        kolor k1(5, 10, 15);
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    try
    {
        kolor k2(256, 0, -5);
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    try
    {
        kolor k3(0, 8, 50);
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    cout << "red k1:" << k1.get_r() << '\n';
    cout << "green k1:" << k1.get_g() << '\n';
    cout << "blue k1:" << k1.get_b() << '\n';

    k1.set_r(10);
    k1.set_g(9);
    k1.set_b(8);
    cout << "red k1:" << k1.get_r() << '\n';
    cout << "green k1:" << k1.get_g() << '\n';
    cout << "blue k1:" << k1.get_b() << '\n';

    k1.darker(0.3);
    cout << "red k1:" << k1.get_r() << '\n';
    cout << "green k1:" << k1.get_g() << '\n';
    cout << "blue k1:" << k1.get_b() << '\n';
    
    try
    {
        k1.lighter(0.7);
    }
    catch(invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    cout << "red k1:" << k1.get_r() << '\n';
    cout << "green k1:" << k1.get_g() << '\n';
    cout << "blue k1:" << k1.get_b() << '\n';
    cout << "red po mixie: " << kolor::mix(k1, k3).get_r() << '\n';
    cout << "green po mixie: " << kolor::mix(k1, k3).get_g() << '\n';
    cout << "blue po mixie: " << kolor::mix(k1, k3).get_b() << '\n';
    cout << "Testowanie klasy kolornazwany" << '\n';
    kolor_nazwany k7(5, 10, 15, "kolor1");
    cout << "Testowanie klasy kolortransparentny" << '\n';
    kolor_transparentny k10(8, 7, 3, 15);
    cout << "Testowanie klasy kolornt" << '\n';
    kolornt k13(5, 7, 13, "kolor2", 10);
    cout << "Testowanie klasy piksel" << '\n';
    piksel p1(10, 15);
    cout << "x p1:" << p1.get_x() << '\n';
    cout << "y p1:" << p1.get_y() << '\n';
    cout << "up: " << p1.get_up() << '\n';
    cout << "down: " << p1.get_down() << '\n';
    cout << "left: " << p1.get_left() << '\n';
    cout << "right: " << p1.get_right() << '\n';
    cout << "Testowanie klasy pikselkolorowy" << '\n';
    pikselkolorowy p2(10, 20, k10);
    p2.move(10, 15);
    piksel p3(30, 49);
    cout << "Testowanie globalnych funkcji" << '\n';
    cout << "odleglosc 1" << piksel::odleglosc(p1, p3) << '\n';
    cout << "odleglosc 2" << piksel::odleglosc(&p1, &p3) << '\n';
}