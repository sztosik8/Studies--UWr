/*
Katarzyna Trzos
Lista 5
Kurs C++
*/

#include "wielom.cpp"
#include <iostream>
using namespace std;

int main()
{
    try
    {
        wielom jednomian = wielom(0, 2.123);
        cout << "Jednomian: " << jednomian << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    double wsp[] = {1.0, 2.0, 3.0};
    wielom wielomian = wielom(2, wsp);
    cout << "Wielomian: " << wielomian << endl;

    wielomian = wielom({1.0, 2.0, 3.0});
    cout << "Wielomian z listy wspolczynnikow: " << wielomian << endl;

    wielom wielomian1 = wielom({1.0, 2.0, 3.0});
    wielom wielomian2(wielomian1);
    cout << "Kopiowany wielomian: " << wielomian2 << endl;

    wielomian1 = wielom({1.0, 2.0, 3.0});
    wielomian2 = move(wielomian1);
    cout << "Przenoszony wielomian: " << wielomian2 << endl;

    wielomian2 = wielomian1;
    cout << "Przypisany wielomian: " << wielomian2 << endl;

    wielomian2 = std::move(wielomian1);
    cout << "Przenoszony przypisany wielomian: " << wielomian2 << endl;

    cout << "Stopien wielomianu: " << wielomian.stopien() << endl;

    cout << "Wartosc wielomianu dla x=2: " << wielomian(2) << endl;

    cout << "Wspolczynnik przy potedze 2: " << wielomian[2] << '\n'
         << '\n';

    wielomian2 = wielom({2.0, 3.0, 4.0});
    cout << "wielomian1 " << wielomian1 << '\n';
    cout << "wielomin2 " << wielomian2 << '\n';
    wielom wielomian3 = wielomian1 + wielomian2;

    
    cout << "Wynik dodawania: " << wielomian3 << endl
         << '\n'
         << '\n';

    cout << "wielomian1 " << wielomian1 << '\n';
    cout << "wielomin2 " << wielomian2 << '\n';

    // cout << "wielomian1 " << wielomian1 <<wielomian2<< '\n';
/*
 wielomian3 = wielomian1 - wielomian2;

    cout << "Wynik odejmowania: " << '\n';

    cout << wielomian3;
    cout << '\n'
         << '\n';

    cout << "Wynik mnozenia przez wielomian: " << (wielomian1 * wielomian2) << endl;

    // wielom wielomian3 = wielomian2 * 4;
    cout << "Wynik mnozenia przez liczba: " << wielomian1 << endl;

    wielomian1 += wielomian2;
    cout << "Wynik dodawania skrocony: " << wielomian1 << endl;

    wielomian1 -= wielomian2;
    cout << "Wynik odejmowania skrocony: " << wielomian1 << endl;

    wielomian *= 2.0;
    cout << "Wynik mnozenia skrocony: " << wielomian << endl;

    try
    {
        cout << wielomian[9];
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    wielom w=wielom();
    cout<<w<<'\n';

    

        try
        {
        }
        catch (invalid_argument const &ex)
        {
            cerr << ex.what() << '\n';
        }


        */
}