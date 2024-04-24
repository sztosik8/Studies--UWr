#include <iostream>
#include <cmath>
using namespace std;

int tab[202];

int count_cycle(int tab[], int x)
{
    int next = tab[x];
    int ans = 1;
    while (next != x)
    {
        ans++;
        next = tab[next];
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            tab[i] = a;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << count_cycle(tab, i) << ' ';
        }
        cout << '\n';
    }
}