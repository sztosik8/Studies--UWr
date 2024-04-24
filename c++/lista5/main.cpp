/*
Katarzyna Trzos
Lista 5
Kurs C++
*/

#include "kolejka.cpp"
#include <iostream>
using namespace std;

int main()
{

    // wstawianie, wypisywanie i usuwanie
    Kolejka k1(10);
    Kolejka k2;
    cout << '\n';
    cout << "kolejak k1 ma " << k1.dlugosc() << " elementow" << '\n';
    cout << "na kolejke k1 wstawiamy A B C " << '\n';
    try
    {
        k1.wstaw("A");
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    try
    {
        k1.wstaw("B");
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    try
    {
        k1.wstaw("C");
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    cout << "teraz kolejak k1 ma " << k1.dlugosc() << " elementow" << '\n'
         << '\n';

    try
    {
        cout << "pierwszym elementem w kolejce jest \"" << k1.zprzodu() << "\" i kolejka ma nadal " << k1.dlugosc() << " elementy" << '\n'
             << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    try
    {
        cout << "usuniemy pierwszy element, ktorym jest \"" << k1.usun() << "\" i ilosc elementow zmniejszy sie do " << k1.dlugosc() << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    try
    {
        cout << "teraz pierwszym elementem w kolejce jest : \"" << k1.zprzodu() << "\" i kolejka ma " << k1.dlugosc() << " elementy" << '\n'
             << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    cout << "dodaje D, E, F i ilosc elementow zmienia sie nastepujaco: " << '\n';

    try
    {
        k1.wstaw("D");
        cout << k1.dlugosc() << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    try
    {
        k1.wstaw("E");
        cout << k1.dlugosc() << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    try
    {
        k1.wstaw("F");
        cout << k1.dlugosc() << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    // kopiowanie i przenoszenie

    cout << "kolejke k1 kopiuje na kolejke k2 " << '\n';
    k2 = k1;

    try
    {
        cout << "pierwsze elementy k1 = " << k1.zprzodu() << " i k2 = " << k2.zprzodu() << " sa takie same" << '\n'
             << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    try
    {
        cout << "gdy usuniemy pierwsze dwa elementy kolejki k2 = " << k2.usun() << ',' << k2.usun() << " wtedy pierwszym elementem stanie sie " << k2.zprzodu() << " , a pierwszy element kolejki k1 zostanie niezmieniony " << k1.zprzodu() << '\n'
             << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    cout << "------- kopiowanie konstruktorem -------" << '\n';

    cout << "tworze kolejke k4 z listy {\"1\", \"2\", \"3\"}" << '\n';
    cout << "kolejke k4 kopiuje na kolejke k5 " << '\n';
    Kolejka k4{"1", "2", "3"};
    Kolejka k5 = k4;

    try
    {
        cout << "pierwsze elementy k5 = " << k5.zprzodu() << " i k4 = " << k4.zprzodu() << " sa takie same" << '\n'
             << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    try
    {
        cout << "gdy usuniemy pierwsze dwa elementy kolejki k4 = " << k4.usun() << ',' << k4.usun() << " wtedy pierwszym elementem stanie sie " << k4.zprzodu() << " , a pierwszy element kolejki k5 zostanie niezmieniony " << k5.zprzodu() << '\n'
             << '\n';
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    k2 = move(k1);
    cout << "gdy przeniesiemy kolejke k1 na kolejke k2 to na kolejce k2 pierwszy element to " << k2.zprzodu() << " natomiast kolejka k1 zostanie usunieta i jej rozmiar to " << k1.dlugosc() << '\n';
    cout << '\n';
    cout << "jak kolejka k1 jest pusta i zaaplikujemy do niej funkcje usun to wyswietla sie komunikat : " << '\n';
    try
    {
        k1.usun();
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    cout << "-----przenoszenie konstruktorem------";
    Kolejka k6 = move(k2);

    cout
        << '\n';
    Kolejka k3 = Kolejka(3);
    cout << "jesli do kolejki k3 o pojemnosci 3 dodamy wiecej niz trzy elementy(np. A B C D) to otrzymamy komunikat : " << '\n';
    try
    {
        k3.wstaw("A");
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    try
    {
        k3.wstaw("B");
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    try
    {
        k3.wstaw("C");
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    try
    {
        k3.wstaw("D");
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    cout << '\n';
    try
    {
        cout << "ale gdy zwolnimy miejsce usuwajac pierwszy element " << k3.usun();
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    cout << "ale gdy zwolnimy miejsce usuwajac pierwszy element " << k3.usun() << " to dodanie kolejnego elementu D nie stworzy nam bledu";
    cout << '\n';
    try
    {
        k3.wstaw("D");
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
    cout << '\n';
}