#include <iostream>
#include <stack>
using namespace std;

long long max_war[1000002];
long long min_war[1000002];
int czym[1000002][3];
int monety[102];
stack<pair<int, int> > s1;
void collect(int f, int c, int min_max)
{
    int curr_ktora = czym[f][min_max];
    int prev_ktora;
    int ile = 1;

    while (f != 0)
    {
        f -= monety[curr_ktora];
        prev_ktora = curr_ktora;
        curr_ktora = czym[f][min_max];

        // cout << prev_ktora << ' ' << curr_ktora <<' '<< ile << " f = " << f << '\n';
        if (curr_ktora == prev_ktora)
        {
            ile++;
            if (f == 0)
                s1.push(make_pair(prev_ktora, ile - 1));
        }
        else
        {
            s1.push(make_pair(prev_ktora, ile));
            ile = 1;
        }
    }

    pair<int, int> x;
    x = s1.top();
    s1.pop();
    for (int it = 0; it < c; it++)
    {
        if (it == x.first)
        {
            cout << x.second << ' ';
            if (!s1.empty())
            {
                x = s1.top();
                s1.pop();
            }
        }
        else
            cout << 0 << ' ';
    }
}

int main()
{
    int f;
    int c;
    cin >> f >> c;

    for (int j = 0; j < c; j++)
    {
        int nom, wag;
        cin >> nom >> wag;

        monety[j]= wag;

        for (int i = 0; i + wag <= f; i++)
        {
            // wyliczanie min
            if (i == 0)
            {
                if (min_war[wag] == 0)
                {
                    min_war[wag] = nom;
                    czym[wag][0] = j;
                }
                else
                {
                    if (min_war[i + wag] > min_war[i] + nom || min_war[i + wag] == 0)
                    {
                        min_war[i + wag] = min_war[i] + nom;
                        czym[i + wag][0] = j;
                    }
                }
            }

            if (min_war[i] != 0)
            {
                if (min_war[i + wag] > min_war[i] + nom || min_war[i + wag] == 0)
                {
                    min_war[i + wag] = min_war[i] + nom;
                    czym[i + wag][0] = j;
                }
            }

            // wyliczanie max
            if (max_war[i] != 0 || i == 0)
            {
                if (max_war[i + wag] < max_war[i] + nom)
                {
                    max_war[i + wag] = max_war[i] + nom;
                    czym[i + wag][1] = j;
                }
            }
        }
    }
    if (max_war[f] == 0)
        cout << "NIE" << '\n';

    else
    {
        cout << "TAK" << '\n';
        cout << min_war[f] << '\n';
        collect(f, c, 0);
        cout << '\n'
             << max_war[f] << '\n';
        collect(f, c, 1);
        cout << '\n';
    }
}