#include <iostream>
#include <cmath>
#include <functional>
using namespace std;

double f(double x) {
    return 5 * pow(x, 2) - 1;
}

double f_prim(double x) {
    return 10 * x;
}

void newton (function<double(double)> f, function<double(double)> f_prim, double x0, double epsilon) {
    double x = x0;
    int i = 0;
    while(abs(f(x)) > epsilon && i < 100) {
        x = x - f(x) / f_prim(x);
        i += 1;
    }
    if(i == 100)
        cout << "Nie znaleziono miejsca zerowego" << endl;
    else
        cout << "Miejsce zerowe to " << x << " Po iteracji równej: " << i << endl;
}


int main() {
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
    for(double i= 0.4; i <= 0.5; i+= 0.01) {
        cout << "x0: " << i << endl;
        newton(&f, &f_prim, i, 0.00000001);
    }
} 