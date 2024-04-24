#include <iostream>
#include <cmath>
#include <functional>
using namespace std;

void newton(double a, double x0, double epsilon)
{
    double x = x0;
    int i = 0;
    while (true)
    {
        double x_new = x - (a * pow(x, 3) - x) / 2;
        i += 1;

        if (abs(x - x_new) < epsilon)
        {
            cout << "Miejsce zerowe to " << x << " Po iteracji równej: " << i << "\n";
            return;
        }
        x = x_new;
    }
}

int main()
{
    double a = 2;

    /*
    for(double i= - 1; i < -0.1; i+= 0.1) {
        cout << "x0: " << i << endl;
         newton(a, i, 0.0001);
    }
    cout<<'\n';
    */

    // newton(a, 1.5, 0.0001);
/*
    for (double i = 1.5; i < 2.0; i += 0.01)
    {
        cout << "x0 = " << i << '\n';
        newton(a, i, 0.0001);
    }
    */
// DLA X >= 1.5812 NIE DLICZY SIE
/*
    for (double i = 1.581; i < 1.6; i += 0.0001)
    {
        cout << "x0 = " << i << '\n';
        newton(a, i, 0.0001);
    }
*/
        for (double i = 0; i >-1; i -= 0.1)
        {
            cout << "x0 = " << i << '\n';
            newton(a, i, 0.0000001);
        }

        cout << '\n';
/*
        for (double i = -1; i >-1.9; i -= 0.01)
        {
            cout << "x0 = " << i << '\n';
            newton(a, i, 0.0000001);
        }*/
/*
        for (double i = -1.58; i >-1.9; i -= 0.001)
        {
            cout << "x0 = " << i << '\n';
            newton(a, i, 0.0000001);
        }
        */

        for (double i = -1.581; i >-1.9; i -= 0.0001)
        {
            cout << "x0 = " << i << '\n';
            newton(a, i, 0.0000001);
        }
    // DLA X <= -1.5812 NIE DLICZY SIE
        

}