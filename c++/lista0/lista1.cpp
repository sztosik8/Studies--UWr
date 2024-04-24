/*
Katarzyna Trzos
Lista 1
Kurs C++
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool tr_help(float x, float y, float z)
{
    return (x + y > z);
}

bool zasada_trojkata(float a, float b, float c)
{
    return (tr_help(a, b, c) && tr_help(c, a, b) && tr_help(b, c, a));
}

float pole(float a, float b, float c)
{
    float p = (a + b + c) / 2;
    float ans = sqrt(p * (p - a) * (p - b) * (p - c));
    return ans;
}
float obwod(float a, float b, float c)
{
    return a + b + c;
}

int main()
{

    float a, b, c;
    cout << fixed << setprecision(3);

    while (cin >> a >> b >> c)
    {
        clog << "Podaj długości boków trójkąta: " << a << ' ' << b << ' ' << c << '\n';

        if (a <= 0 || b <= 0 || c <= 0)
        {
            clog << "Długości boków muszą być dodatnie." << '\n';
            continue;
        }

        if (!zasada_trojkata(a, b, c))
        {
            cerr << "Z podanych długości nie można zbudować trójkąta." << '\n';
            continue;
        }
        // cout << "Boki: " << a << ' ' << b << ' ' << c << '\n';
        cout << obwod(a, b, c) << '\n';
        cout << pole(a, b, c) << '\n'
             << '\n';
    }

    return 0;
}