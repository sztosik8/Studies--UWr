// Katarzyna Trzos
// 340066
// KPO

#include <iostream>
using namespace std;

int sito[1003];
int pierwsze[1000];

void sito_era()
{
    sito[0] = 1;
    sito[1] = 1;
    int point = 0;
    for (int i = 2; i < 1010; i++)
    {
        if (sito[i] == 0)
        {
            pierwsze[point] = i;
            point++;

            int j = 2;
            while (i * j < 1001)
            {
                sito[i * j] = 1;
                j++;
            }
        }
    }
}

void rozloz(int n)
{
    int i = 0;
    int org = n;

    while (n > 1 && pierwsze[i] * pierwsze[i] <= org)
    {
        while (n % pierwsze[i] == 0)
        {
            cout << pierwsze[i] << ' ';
            n /= pierwsze[i];
        }
        i++;
    }
    if (n > 1)
    {
        cout << n;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sito_era();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        rozloz(n);
        cout << '\n';
    }

    // najwieksza liczba pierwsza 999979 mniejsza od 1000000
}