#include <iostream>
#include <stack>

using namespace std;

long long max_war[1000006];
long long min_war[1000006];
int czym[1000006][3];
int monety[102][3];
stack<pair<int, int> > s1;

// dziaaaalaaaa
void coll(int f, int c, int min_max)
{
    int curr_ktora = czym[f][min_max];
    int prev_ktora;
    int ile = 1;

    while (f != 0)
    {
        f -= monety[curr_ktora][1];
        prev_ktora = curr_ktora;
        curr_ktora = czym[f][min_max];

        // cout << monety[prev_ktora][0] << ' ' << monety[curr_ktora][0] << ile << " f = " << f << '\n';
        if (curr_ktora == prev_ktora)
        {
            ile++;
            if (f == 0)
                s1.push(make_pair(monety[prev_ktora][0], ile - 1));
        }
        else
        {
            s1.push(make_pair(monety[prev_ktora][0], ile));
            ile = 1;
        }
    }

    pair<int, int> x;
    x = s1.top();
    s1.pop();
    for (int it = 0; it < c; it++)
    {
        if (monety[it][0] == x.first)
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
        monety[j][0] = nom;
        monety[j][1] = wag;
        for (int i = 0; i + wag <= f; i++)
        {
            if (max_war[i] != 0 || i == 0)
            {
                if (max_war[i + wag] < max_war[i] + nom)
                {
                    max_war[i + wag] = max_war[i] + nom;
                    czym[i + wag][0] = j;
                }
            }

            if (min_war[i] != 0 || i == 0)
            {
                if (min_war[i + wag] == 0)
                {
                    min_war[i + wag] = min_war[i] + nom;
                    czym[i + wag][1] = j;
                }
                else if (min_war[i + wag] > min_war[i] + nom)
                {
                    min_war[i + wag] = min_war[i] + nom;
                    czym[i + wag][1] = j;
                }
            }
        }
    }
cout<<"max_war "<<'\n';
    for(int i=0; i<=f; i++)
    {
        cout<<max_war[i]<<' ';
    }
    cout<<'\n'<<"min_war "<<'\n';
    for(int i=0; i<=f; i++)
    {
        cout<<min_war[i]<<' ';
    }

    if (max_war[f] == 0)
        cout << "NIE" << '\n';

    else
    {
        cout << "TAK" << '\n';

        cout << min_war[f] << '\n';
        //coll(f, c, 1); // 1 bo w pierwszym wierszu trzymamy dane dla minimum
        cout << '\n';

        cout << max_war[f] << '\n';
        //coll(f, c, 0); // 0 bo w zerowym wierszu trzymamy dane dla maximum
        cout << '\n';
    }
}