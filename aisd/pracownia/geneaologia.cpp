#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

pair<int, int> krawedzie[1000006]; // ojciec-syn
pair<int, int> ind[1000006];       // indeksy w krawedziach dla danego ojca
stack<int> stos;
int pre[1000006];
int post[1000006];

void indeksy(int n)
{
    int beg, end;
    beg = 0;
    end = 0;
    while (end < n)
    {
        while (krawedzie[end].first == krawedzie[end + 1].first)
        {
            end++;
        }
        ind[krawedzie[end].first] = make_pair(beg, end);
        beg = end + 1;
        end++;
    }
}

void dfs_it(int v)
{
    int t = 0;
    stos.push(v);

    while (!stos.empty())
    {
        int u = stos.top();
        if (pre[u] == 0)
        {
            pre[u] = ++t;

            /*cout << '\n'
                 << "beg - " << ind[u].first << "  end - " << ind[u].second << '\n';
            cout << '\n'
                 << u << " : ";*/

            for (int i = ind[u].first; i <= ind[u].second; i++)
            {
                int son = krawedzie[i].second;
                // cout << son << ' ';
                if (son != 0)
                {
                    stos.push(son);
                }
            }
        }
        else
        {
            post[u] = ++t;
            stos.pop();
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) // ------- O(n)
    {
        int v;
        cin >> v;
        krawedzie[i - 2] = make_pair(v, i);
    }

    sort(krawedzie, krawedzie + n); // ------- O(n log n)

    // policz indeksy ojcow
    indeksy(n); // ------- O(n)

    dfs_it(1);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        if (pre[a] < pre[b] && post[b] <= post[a])
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }
    /*
        // ---------------------------------- TESTOWANIE ----------------------

        cout << "krawedzie" << '\n';
        for (int i = 1; i < n; i++)
        {
            cout << krawedzie[i].first << ' ' << krawedzie[i].second << '\n';
        }
        cout << '\n';
        cout << "indeksy" << '\n';
        for (int i = 1; i <= n; i++)
        {
            cout << i << " : " << ind[i].first << ' ' << ind[i].second << '\n';
        }
        cout << '\n';
        cout << "pre i post" << '\n';
        for (int i = 1; i <= n; i++)
        {
            cout << i << " : " << pre[i] <<"   " <<post[i]<< '\n';
        }
        */

    // 8 7 1 1 2 2 3 6 6
    // 11 7 1 1 2 2 3 6 6 7 7 10
    // 5 4 1 1 3 3
}