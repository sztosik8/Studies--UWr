#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double pi_approx(int k)
{
    double ans = 0.0;
    for (int i = 0; i <= k; i++)
    {
        ans += pow(-1.0, i) / ((2.0 * i) + 1.0);
    }
    return 4.0 * ans;
}

int main()
{
    cout << setprecision(9) << (double)pi_approx(199999) << ' ';
    cout << setprecision(9) << (double)pi_approx(2000000) << ' ';
}