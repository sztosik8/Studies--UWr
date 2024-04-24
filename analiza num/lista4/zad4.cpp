#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
    double ans = x * x;
    ans *= ans;
    x += 4;
    return (ans - log(x));
}

int main()
{

    double a = -2, b = 1;
    double m;
    // pierwsze miejsce
    for (int i = 0; i < 10; i++)
    {
        m = (a + b) / 2;
        cout << m << '\n';
        if (f(m) == 0)
            break;
        if (f(m) < 0)
            b = m;
        else
            a = m;
    }
    cout << '\n';
    // drugie miejsce
    a = 1;
    b = 2;

    for (int i = 0; i < 10; i++)
    {
        m = (a + b) / 2;
        cout << m << '\n';
        if (f(m) == 0)
            break;
        if (f(m) > 0)
            b = m;
        else
            a = m;
    }
}
