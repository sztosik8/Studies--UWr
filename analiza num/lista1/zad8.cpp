#include <iostream>
#include <cmath>

using namespace std;

double atg(double x)
{
    if (x == 0.0)
        return 0;
    if (x > 0)
        return (M_PI / 2.0) - atg(1.0 / x);
    else
        return -(M_PI / 2.0) - atg(1.0 / x);
}

int main()
{
    cout << atg(5) << '\n';
}