#include <iostream>
#include <cmath>
using namespace std;

int tab[1000003];

int ile_mniej(int x, int n)
{
    if (x <= tab[0])
        return n;
    if(x> tab[n-1])
        return 0;
    int beg = 0, end = n - 1;

    while (end - beg > 1)
    {
        int mid = (end + beg) / 2;

        if (x <= tab[mid])
        {
            end = mid;
        }
        else
            beg = mid;
    }
    return n - beg - 1;
}

int main()
{
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        tab[i] = el;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        cout << ile_mniej(x, n) << '\n';
    }
}
// 10   3 4 8 11 23 54 996 8710 911147 10001010  11   1 0 8 64 99 114 334 8484 41 911147 1000000000
// 8   8 11 23 54 996 8710 911147 10001010  11   1 0 8 64 99 114 334 8484 41 911147 1000000000

// 10   3 4 8 11 23 54 996 8710 911147 10001010   8   8 64 99 114 334 8484 41 911147

// 7 2 4 6 8 10 12 14 4 15 14 2 1