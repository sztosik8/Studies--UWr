#include <iostream>
#include <stack>

using namespace std;

long long max_war[1000006];
long long min_war[1000006];
int czym[1000006][3];
int monety[102][3];
stack<pair<int, int> > s1;
stack<int> s;

void zlicz(int c)
{
    int it = 0;
    int a = s.top();
    s.pop();
    while (it < c)
    {
        int ile = 0;
        while (a == monety[it][0])
        {
            ile++;

            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
                break;
        }

        // cout << ile << ' ';
        it++;
    }
}

void collect(int f, int c, int min_max)
{
    while (f != 0)
    {
        int moneta_ktora = czym[f][min_max];
        s.push(monety[moneta_ktora][0]);
        // cout << monety[moneta_ktora][0] << ' ';

        f -= monety[moneta_ktora][1];
    }
    // s.push(0);
    zlicz(c);
}

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
            {
                s1.push(make_pair(monety[prev_ktora][0], ile - 1));
            }
        }
        else
        {
            s1.push(make_pair(monety[prev_ktora][0], ile));
            ile = 1;
        }
    }
    //cout << "sots : " << '\n';

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
        {
            cout << 0 << ' ';
        }

        // cout << x.first << ' ' << x.second << '\n';
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

                    // co_skad[i + wag][0] = wag;
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

    if (max_war[f] == 0)
    {
        cout << "NIE" << '\n';
    }
    else
    {
        cout << "TAK" << '\n';
        cout << min_war[f] << '\n';
        //collect(f, c, 1); // 1 bo w pierwszym wierszu trzymamy dane dla minimum
        coll(f, c, 1);

        // coll_min(f);
        cout << '\n';
        //collect(f, c, 0); // 0 bo w zerowym wierszu trzymamy dane dla maximum
        cout << max_war[f] << '\n';
        coll(f, c, 0);   
        // coll_max(f);
        cout << '\n';
    }
    /*
        for (int i = 0; i < f; i++)
        {
            cout << i << ' ';
        }
        cout << '\n';
        for (int i = 0; i <= f; i++)
        {
            cout << max_war[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i <= f; i++)
        {
            cout << min_war[i] << ' ';
        }
        cout << '\n';
        cout << '\n';
        for (int i = 0; i <= f; i++)
        {
            cout << czym[i][0] << ' ';
        }
        cout << '\n';
        for (int i = 0; i <= f; i++)
        {
            cout << czym[i][1] << ' ';
        }*/
    // cout << '\n';
}