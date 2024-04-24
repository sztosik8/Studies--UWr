#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x = 0.001;

    double result = 4046 * sqrt(pow(x, 14) + 1) - 1 / pow(x, 14);
    cout << result << '\n';

    double result2 = 4046 / ((sqrt(pow(x, 14) + 1)) + 1);
    cout << result2 << '\n';
}
