#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

pair<int, int> pointx[500005];
pair<int, int> pointy[500005];
pair<int, int> v_obw_min[5];
double min_obw = INT_MAX;

double len(int a, int b)
{
    double x = pointx[a].first - pointx[b].first;
    double y = pointx[a].second - pointx[b].second;
    return sqrt(x * x + y * y);
}

double obw(int a, int b, int c)
{
    double p = len(a, b) + len(b, c) + len(c, a);
    return p;
}

double leny(int a, int b)
{
    double x = pointy[a].first - pointy[b].first;
    double y = pointy[a].second - pointy[b].second;
    return sqrt(x * x + y * y);
}
double obwy(int a, int b, int c)
{
    double p = leny(a, b) + leny(b, c) + leny(c, a);
    return p;
}

void kaz_z_kaz(int a, int b)
{
    // cout << "kazdy z kazdym :  -------------------------" << '\n';
    for (int i = a; i <= b - 2; i++)
    {
        for (int j = i + 1; j <= b - 1; j++)
        {
            for (int k = j + 1; k <= b; k++)
            {
                // cout << i << ' ' << j << ' ' << k << '\n';
                double obecny_obw = obw(i, j, k);

                if (obecny_obw < min_obw)
                {
                    min_obw = obecny_obw;
                    // cout << "zmieniam odp na 1 : " << min_obw << '\n';
                    v_obw_min[0] = pointx[i];
                    v_obw_min[1] = pointx[j];
                    v_obw_min[2] = pointx[k];
                }
            }
        }
    }
    // cout << "------------------------------------------------" << '\n';
}

void minimalny(int a, int b)
{
    // cout << '\n';
    // cout << "poczatek petli   a = " << a << "  b= " << b << '\n';

    if (b - a + 1 < 6)
    {

        /*cout << "wszytskie punkty z najmniejszego przedzialu ab " << a << ' ' << b << '\n';
        for (int i = a; i <= b; i++)
        {
            cout << pointx[i].first << ' ' << pointx[i].second << '\n';
        }*/
        kaz_z_kaz(a, b);
    }
    else
    {
        int mid = floor((b + a) / 2);
        minimalny(a, mid);
        minimalny(mid + 1, b);

        // cout << "mid = " << mid << "  mid+1 =  " << mid + 1 << '\n';
        // cout << "point[mid].first =  " << pointx[mid].first << "       point[mid+1].first = " << pointx[mid + 1].first << '\n';

        double X = (double)(pointx[mid].first + pointx[mid + 1].first) / 2;
        // cout << "prosta X = " << X << '\n';

        int ile = 0;
        double d = min_obw;
        // cout << "wszytskie punkty z przedzialu a b  " << a << ' ' << b << '\n';
        for (int i = a; i <= b; i++) // mozna szybciej
        {
            // cout << pointx[i].first << '\n';

            if (pointx[i].first <= (d / 2) + X and pointx[i].first >= X - (d / 2))
            {
                while (pointx[i].first <= (d / 2) + X and pointx[i].first >= X - (d / 2) and i <= b)
                {
                    pointy[ile] = make_pair(pointx[i].second, pointx[i].first);
                    ile++;
                    i++;
                }
                break;
            }
        }
        // cout << '\n';

        sort(pointy, pointy + ile);
        /*cout << "pointy dla prostej X =  " << X << "  i odleglosci d " << d << "z przedzialu (" << d + X << ',' << X - d << ')' << '\n';
        for (int i = 0; i < ile; i++)
        {
            cout << pointy[i].second << "  " << pointy[i].first << '\n';
            // pointy[i] = make_pair(0, 0);
        }*/

        for (int i = 0; i <= ile - 2; i++)
        {
            for (int j = i + 1; j < ile - 1; j++)
            {
                if (abs(pointy[j].first - pointy[i].first) >= d / 2)
                {
                    i++;
                    j = i;
                }
                else
                {
                    for (int k = j + 1; k < ile; k++)
                    {
                        // cout << "porownuje indeksy i j k : " << i << ' ' << j << ' ' << k << '\n';
                        if (abs(pointy[k].first - pointy[i].first) >= d / 2)
                        {
                            // cout << "zmiana indeksow i : " << i << ' ' << j << ' ' << k << '\n';
                            j++;
                            k = j;
                        }
                        else
                        {
                            double obecny_obw = obwy(i, j, k);
                            if (obecny_obw < min_obw)
                            {
                                /*
                                cout << pointy[i].second << "  " << pointy[i].first << '\n';
                                cout << pointy[j].second << "  " << pointy[j].first << '\n';
                                cout << pointy[k].second << "  " << pointy[k].first << '\n';*/
                                min_obw = obecny_obw;
                                // cout << "zmieniam odp na 2 : " << min_obw << '\n';
                                v_obw_min[0] = make_pair(pointy[i].second, pointy[i].first);
                                v_obw_min[1] = make_pair(pointy[j].second, pointy[j].first);
                                v_obw_min[2] = make_pair(pointy[k].second, pointy[k].first);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= ile; i++)
        {
            // cout << pointy[i].second << "  " << pointy[i].first << '\n';
            pointy[i] = make_pair(0, 0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pointx[i] = make_pair(x, y);
    }

    sort(pointx, pointx + n);

    minimalny(0, n - 1);

    /*
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << pointx[i].first << ' ' << pointx[i].second << '\n';
    }
    cout << '\n';*/

    // cout << "obwod min = " << min_obw << '\n'     << " punkty" << '\n';
    for (int i = 0; i < 3; i++)
    {
        cout << v_obw_min[i].first << ' ' << v_obw_min[i].second << '\n';
    }
}
