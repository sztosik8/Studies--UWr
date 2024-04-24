#include <iostream>
#include <cmath>
using namespace std;

int tab[100002];

int main()
{
    int n, m, l;
    // n linia wlosow
    // m rzadania
    //  l dlugosci wlosa
    cin >> n >> m >> l;
    int time = 0;

    for (int j = 0; j < n; j++)
    {
        int x;
        cin >> x;
        tab[j] = x;
    }

    for (int j = 0; j < n; j++)
    {
        if (tab[j] > l)
        {
            time++;
            while (j < n && tab[j] > l)
            {
                j++;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            cout << time << '\n';
        }
        else
        {
            int p, d;
            cin >> p >> d;
            p--;
            tab[p] += d;
            if (tab[p] - d <= l && tab[p] > l)
            {
                if (tab[p + 1] <= l)
                {
                    if (p > 0 && tab[p - 1] <= l)
                        time++;
                    if (p == 0)
                        time++;
                }
                if ((tab[p + 1] > l))
                {
                    if (p > 0 && tab[p - 1] > l)
                        time--;
                }
             
            }
        }
    }
}