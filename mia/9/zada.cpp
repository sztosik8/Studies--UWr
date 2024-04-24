#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int tab[5003];
int vis[5003];

bool cycle3(int x)
{
    int ans = 0;

    while (vis[x] != 1)
    {
        vis[x] = 1;
        x = tab[x];
        ans++;
    }
    if (ans == 3)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tab[i] = x;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            if (cycle3(i))
            {
                cout << "YES" << '\n';
                return 0;
            }
        }
    }
    cout << "NO" << '\n';
}
