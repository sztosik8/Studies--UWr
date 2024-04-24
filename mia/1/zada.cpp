#include <iostream>
#include <cmath>
using namespace std;

int tab[203][203];

int list[1000];

int val(int i, int j, int n, int m)
{
    int ans = 0;

    int k = i, l = j;
    while (k >= 0 && l >= 0)
    {
        ans += tab[k][l];
        k--;
        l--;
    }

    k = i;
    l = j;
    while (k < n && l < m)
    {
        ans += tab[k][l];
        k++;
        l++;
    }
    k = i;
    l = j;
    while (k >= 0 && l < m)
    {
        ans += tab[k][l];
        k--;
        l++;
    }
    k = i;
    l = j;
    while (k < n && l >= 0)
    {
        ans += tab[k][l];
        k++;
        l--;
    }
    return ans - 3 * tab[i][j];
}

int main()
{
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                tab[i][j] = x;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ans < val(i, j, n, m))
                {
                    ans = val(i, j, n, m);
                }
            }
        }
        list[p] = ans;
    }
    for (int i = 0; i < t; i++)
    {
        cout << list[i] << '\n';
    }
}
