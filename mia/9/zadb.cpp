#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tab[100005];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        tab[x - 1]++;
        tab[y - 1]++;
    }

    sort(tab, tab + n);

    if (tab[0] == 2 && tab[n - 1] == 2)
    {
        cout << "ring topology" << '\n';
    }
    else if (tab[0] == 1 && tab[n - 1] == m && tab[n - 2] == 1)
    {
        cout << "star topology" << '\n';
    }
    else if (tab[n - 1] == 2 && tab[0] == tab[1] && tab[0] == 1)
    {
        cout << "bus topology" << '\n';
    }
    else
    {
        cout << "unknown topology" << '\n';
    }
}
