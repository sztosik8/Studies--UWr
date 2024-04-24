#include <iostream>

using namespace std;
void wypisz(int x, int y)
{
    while (x <= y)
    {
        cout << x << '\n';
        x++;
    }
}

int main()
{
    int x, y;
    cin >> x >> y;
    if (x > y)
        wypisz(y, x);
    else
        wypisz(x, y);

    return 0;
}