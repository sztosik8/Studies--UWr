/*
Katarzyna Trzos
340066
KPO
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int x, n;
    

    cin >> x >> n;
    int ans = 1;
    int poz = x;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= poz;
            
        }
        poz *= poz;
        n /= 2;
    }
    cout << ans << '\n';
}