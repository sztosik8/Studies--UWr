#include <iostream>
#include <cmath>

using namespace std;
// f(x) = x − 0.49

double f(double x)
{
    return (x - 0.49);
}
double e(int n)
{
    double ans = pow(2, -(n + 1));
    return ans;
}

int main()
{
    double a = 0, b = 1;
    double m;

    for (int i = 0; i < 5; i++)
    {
        m = (a + b) / 2;
        cout << "blad oszacowania " <<abs(0.49 - m);
        cout << "  |e| = " << e(i) << '\n';

        if (f(m) > 0)
            b = m;
        else
            a = m;
    }
   // cout << "poprawne rozw: 0.49 "<<'\n';
}
