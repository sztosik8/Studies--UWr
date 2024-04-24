#include <iostream>
#include <cmath>
using namespace std;

double I_rek(int n)
{
    if (n == 0)
        return log(2024.0 / 2023.0);
    else
        return (1.0 / n) - (2023 * I_rek(n - 1));
}

double I_iter(int n)
{
    double In = log(2024.0 / 2023.0);

    for (int i = 1; i <= n; i++)
    {
        double Inew = ((double)1 / i) - (2023 * In);
        In = Inew;
    }

    return In;
}

int main()
{

    for (int i = 1; i <= 19; i += 2)
    {
        cout << I_rek(i) << "    ";
        cout << I_iter(i) << '\n';
    }
    cout << "\n";
    for (int i = 2; i <= 20; i += 2)
    {
        cout << I_rek(i) << "    ";
        cout << I_iter(i) << '\n';
    }
}
