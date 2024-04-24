#include <iostream>
using namespace std;

long long fast_pow(int n, int m)
{
    // matrix as |a b| = |0 1|
    //           |c d|   |1 1|

    long long a = 0, b = 1, c = 1, d = 1;
    long long a1, b1, c1, d1;
    long long a_temp = 0, b_temp = 1, c_temp = 1, d_temp = 1;

    n--;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            // mnozenie macierzy wynikowej abcd ze spotegowana a_temp, b_temp...
            a1 = (a * a_temp + b * c_temp) % m;
            b1 = (a * b_temp + b * d_temp) % m;
            c1 = (c * a_temp + d * c_temp) % m;
            d1 = (c * b_temp + d * d_temp) % m;

            a = a1;
            b = b1;
            c = c1;
            d = d1;
        }

        // potegowanie
        a1 = (a_temp * a_temp + b_temp * c_temp) % m;
        b1 = (a_temp * b_temp + b_temp * d_temp) % m;
        c1 = (c_temp * a_temp + d_temp * c_temp) % m;
        d1 = (c_temp * b_temp + d_temp * d_temp) % m;

        a_temp = a1;
        b_temp = b1;
        c_temp = c1;
        d_temp = d1;

        n /= 2;
    }
    /*
    cout << "Resultant matrix:" << endl;
    cout << a << ' ' << b << endl;
    cout << c << ' ' << d << endl;
    */
    return b % m;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long n, m;
        cin >> n >> m;

        cout << fast_pow(n, m) << '\n';
    }
}
// 5 46 10 47 10 48 10 49 10 50 10
// 10 1 10 2 10 3 10 4 25 5 25 6 25 7 27 8 29 9 31 10 33
// 2 1 10 2 10