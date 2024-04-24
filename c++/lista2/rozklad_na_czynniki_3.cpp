/*
Katarzyna Trzos
Lista 2
Kurs C++
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int64_t> rozklad(int64_t n)
{
    vector<int64_t> ans;
    if (n < 0)
    {
        n *= -1;
        ans.push_back(-1);
    }

    int64_t i = 2;
    while (n > 1)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
        i++;
    }
    return ans;
}

void wypisz(int64_t x, vector<int64_t> v)
{
    int i = 0;
    cout << x << " = " << v[i];
    for (i = 1; i < v.size(); i++)
    {
        cout << " * " << v[i];
    }
    cout << '\n';
}

// 9223372036854775783
int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        cerr << "Brak argumentów." << '\n';
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        try
        {
            int64_t x = stoll(argv[i], nullptr, 10);

            vector<int64_t> v = rozklad(x);
            wypisz(x, v);
        }
        catch (invalid_argument const &x)
        {
            cerr << " Funkcja stoll() nie działa poprawnie " << '\n';
        }
    }
}