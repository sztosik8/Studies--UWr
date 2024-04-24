#include <iostream>

using namespace std;
int main()
{

    double y0 = 1;
    double y1 = (double)-1 / 9;
    cout << y0 << ' ' << y1 << '\n';

    for (int i = 0; i < 50; i++)
    {
        double y = y0 + (y1 / 9 * 80);
        cout << y << '\n';
        y0 = y1;
        y1 = y;
    }
}
