/*
Katarzyna Trzos
Alorytmy i struktury danych
Pracownia 4
Chinska komorka
*/
#include <iostream>
using namespace std;

int lit[10003];
int sum[10003];
int len[10003];
int previ[10003];
long long comb[10003];
int ans;

void comb_first_values(int l)
{
    for (int i = 1; i < l; i++)
    {
        int next = i + 1;
        comb[i] = lit[i] + 2 * lit[next];
    }
}
int min_comb_ind()
{
    int i = 1;
    int ans = i, min_val = comb[i];

    int next = i + len[i];
    while (lit[next] != 0)
    {
        if (comb[i] <= min_val)
        {
            min_val = comb[i];
            ans = i;
        }
        i = next;
        next = i + len[i];
    }
    return ans;
}

void set_comb(int i)
{
    int next = i + len[i];
    comb[i] = lit[i] + lit[next] + len[i] * sum[next];
}

void combine()
{
    int i = min_comb_ind();
    // cout << "min indeks  comb = " << i << "  i wartosc comb : " << comb[i]<<'\n';
    int next = i + len[i];
    int previous = previ[i];

    ans -= lit[i];
    ans -= lit[next];
    ans += comb[i];

    sum[i] += sum[next];
    lit[i] = comb[i];
    set_comb(previous);
    len[i] += len[next];
    set_comb(i);
    previ[i + len[i]] = i;
}

int main()
{
    int k, l;
    cin >> k >> l;

    for (int i = 1; i <= l; i++)
    {
        int f;
        cin >> f;
        lit[i] = f;
        sum[i] = f;
        previ[i] = i - 1;
        len[i] = 1;
        ans += f;
    }
    comb_first_values(l);

    while (l - k > 0)
    {
        combine();
        k++;
    }

    cout << ans << '\n';

    int i = 1;
    while (lit[i] != 0)
    {
        cout << len[i] << ' ';
        i += len[i];
    }
}
