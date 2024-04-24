#include <iostream>
using namespace std;

long long szybkie_potegowanie(long long a, long long b, long long m)
{

    long long poz = a;
    long long ans = 1;

    while (b > 0)
    {

        if (b % 2 == 1)
        {
            ans = (ans * poz) % m;
        }
        poz = (poz * poz) % m;
        b /= 2;
    }

    return ans ;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long a, b, m;
        cin >> a >> b >> m;

        cout << szybkie_potegowanie(a, b, m) << '\n';
    }
}
