#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a = 1, b = -100000, c = 1;

    cout <<'\n'<< "z zadania"<<'\n'; 
    cout << "x1 = " << (-b + sqrt((b * b) - 4 * a * c)) / 2 * a << " ";
    cout << "x2 = " << (-b - sqrt((b * b) - 4 * a * c)) / 2 * a << '\n';

    double w = (-b / (2 * a));
    double v = (c / a);

    cout<<'\n'<<"poprawiony"<<'\n';
    if(b < 0)
    {
        cout << "x1 = " << (-b + sqrt((b * b) - 4 * a * c)) / 2 * a << " ";
        cout << "x2 = " << w - sqrt((w * w) - v) << '\n';

    }
    else
    {
        cout << "x1 = " << w + sqrt((w * w) - v) << " ";
        cout << "x2 = " << (-b - sqrt((b * b) - 4 * a * c)) / 2 * a << '\n';

    }
    cout<<'\n';

    
   
}