
#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int vis[100005];
int kolory[100005];
queue<int> q;

void bfs(int obecny)
{
    q.push(obecny);
    vis[obecny] = 1;

    while (q.size() != 0)
    {
        for (int i = 0; i < v[q.front()].size(); i++)
        {
            int aktualny = v[q.front()][i];
            if (vis[aktualny] == 0)
            {
                vis[aktualny] = vis[q.front()] + 1;
                q.push(aktualny);
            }
        }
        q.pop();
    }
}

int main()
{
    int wierz, kraw, s, odl;
    cin >> wierz >> kraw >> s >> odl;

    for (int i = 0; i < kraw; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(s);

    for (int i = 1; i <= wierz; i++)
    {
        if (vis[i] - 1 == odl)
            cout << i << ' ';
    }
}