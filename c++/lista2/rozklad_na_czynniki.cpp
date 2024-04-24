/*
Katarzyna Trzos
Lista 2
Kurs C++
*/
#include <iostream>
#include <vector>
using namespace std;

int sito[100000000];
int pierwsze[10000000];

void sito_era()
{
    sito[0] = 1;
    sito[1] = 1;
    int point = 0;
    for (int i = 2; i < 1000044; i++)
    {
        if (sito[i] == 0)
        {
            pierwsze[point] = i;
            point++;

            int j = 2;
            while (i * j < 100000)
            {
                sito[i * j] = 1;
                j++;
            }
        }
    }
}

vector<int64_t> rozklad(int64_t n)
{
    int i = 0;
    int org = n;
    vector<int64_t> ans;
    if (n < 0)
    {
        ans.push_back(-1);
        n *= -1;
    }

    while (n > 1 && pierwsze[i] * pierwsze[i] <= org)
    {
        while (n % pierwsze[i] == 0)
        {
            // cout << pierwsze[i] << ' ';
            ans.push_back(pierwsze[i]);
            n /= pierwsze[i];
        }
        i++;
    }
    if (n > 1)
    {
        // cout << n;
        ans.push_back(n);
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

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Brak argumentów." << '\n';
        return 1; // Wyrzucenie błędu
    }

    sito_era();

    for (int i = 1; i < argc; i++)
    {
        try
        {
            int64_t x = stoll(argv[i], nullptr, 10);
            vector<int64_t> v = rozklad(x);
            wypisz(x, v);
        }
        catch (...)
        {
            cerr << "Podana liczba nie jest typu int64_t "  << '\n';
            
        }
    }
}