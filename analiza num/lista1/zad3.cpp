#include <iostream>
#include <cmath>

using namespace std;

float f1(float x)
{

    float val = 14 * (1 - cos(17 * x)) / pow(x, 2);

    return val;
}

double f2(double x)
{

    double val = 14 * (1 - cos(17 * x)) / pow(x, 2);

    return val;
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        cout << f1((float)pow(10, -i)) << ' ';
        cout << f2(pow(10, -i)) << '\n';
    }
}