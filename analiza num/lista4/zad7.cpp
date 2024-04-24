#include <iostream>
#include <cmath>
#include <functional>
using namespace std;

double newton(double a, double x0, double epsilon)
{
    double x_new = x0;
    int i = 0;
    while (true)
    {
        double x_new = x - f(x) / f_prim(x);
        i += 1;

        if (abs(f(x_new)) < epsilon)
        {
            cout << "Miejsce zerowe to " << x << " Po iteracji równej: " << i << "\n";
            return;
        }
        x = x_new;
    }
}

int main() {
    cout << newton(22.0, 10.0, 0.00000001) << '\n';
    cout << newton(2.0, 0.5, 0.00000001) << '\n';
    cout << newton(16.0, 1000.0, 0.00000001) << '\n';
    cout << newton(5.0, 10000.0, 0.00000001) << '\n';


    /*for(int i= - 100; i <= 100; i+=10) {
        cout << "x0: " << i << endl;
        newton(&f, &f_prim, i, 0.00000001);
    }
    for(int i= - 10; i <= 10; i++) {
        cout << "x0: " << i << endl;
        newton(&f, &f_prim, i, 0.00000001);
    }
    for(double i= - 1; i <= 1; i+= 0.1) {
        cout << "x0: " << i << endl;
        newton(&f, &f_prim, i, 0.00000001);
    }
    */
}