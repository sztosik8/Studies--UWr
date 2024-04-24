/*
Katarzyna Trzos
Lista 2
Kurs C++
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int sito[10003];
int64_t pierwsze[10000];

void sito_era()
{
    sito[0] = 1;
    sito[1] = 1;
    int point = 0;
    for (int i = 2; i < 10010; i++)
    {
        if (sito[i] == 0)
        {
            pierwsze[point] = i;
            point++;

            int j = 2;
            while (i * j < 10001)
            {
                sito[i * j] = 1;
                j++;
            }
        }
    }
}

pair<vector<int64_t>, int64_t> rozloz_help(int64_t n)
{
    int i = 0;
    int org = n;
    vector<int64_t> ans;

    while (n > 1 && pierwsze[i] * pierwsze[i] <= org)
    {
        while (n % pierwsze[i] == 0)
        {
            ans.push_back(pierwsze[i]);
            n /= pierwsze[i];
        }
        i++;
    }
    return make_pair(ans, n);
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int64_t g(int64_t x, int64_t n)
{
    return ((x * x) + 1) % n;
}

vector<int64_t> rozklad(int64_t n)
{
    int64_t x, y, d;
    vector<int64_t> ans;

    if (n < 0)
    {
        n *= -1;
        ans.push_back(-1);
    }

    while (n > 1)
    {
        int64_t x, y, d;
        x = 2;
        y = x;
        d = 1;
        while (d == 1)
        {
            x = g(x, n);
            y = g(y, n);
            y = g(y, n);

            d = gcd(abs(x - y), n);
        }
        ans.push_back(d);
        n/=d;
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