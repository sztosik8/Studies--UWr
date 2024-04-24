#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graf[100003];
int sor[100003];
int top[100003];
priority_queue<int> q;

int main()
{


    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        sor[b] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (sor[i] == 0)
            q.push(i);
    }

    int a = 0;
    while (q.size() > 0)
    {
        int x = q.top();
        q.pop();
        top[a] = x;
        a++;
        
        for (int i = 0; i < graf[x].size(); i++)
        {
            sor[graf[x][i]]--;
            if (sor[graf[x][i]] == 0)
            {
                q.push(graf[x][i]);
            }
        }
    }

    if (a != n)
        cout << "NIE";
    else
    {
        for (int i = 0; i < n; i++)
            cout << top[i] << " ";
    }

    return 0;
}