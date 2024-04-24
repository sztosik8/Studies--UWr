#include <iostream>
using namespace std;

int lit[10003];
int sum[10003];
int len[10003];
int previ[10003];
long long comb[10003];


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
    //cout << "min indeks  comb = " << i << "  i wartosc comb : " << comb[i]<<'\n';
    int next = i + len[i];
    int new_butt = comb[i];
    int previous = previ[i];

    sum[i] += sum[next];
    lit[i] = new_butt;
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
    }
    comb_first_values(l);
    
        while (l-k > 0)
        {
            combine();
            k++;  
        }
 

    int it = 0;
    int ans = 0;
    int i = 1;
    while (lit[i] != 0)
    {
        ans += lit[i];
        previ[it] = len[i];
        i += len[i];
        it++;
    }

    cout << ans << '\n';
    for (int i = 0; i < it; i++)
    {
        cout << previ[i] << ' ';
    }
/*
    cout << '\n'
         << '\n';
    cout << "it.  ";
    for (int i = 0; i < 10; i++)
    {
        cout << i << ' ';
    }
    cout << '\n';
    cout << "lit  ";
    for (int i = 0; i < 10; i++)
    {
        cout << lit[i] << ' ';
    }
    cout << '\n';
    cout << "sum  ";
    for (int i = 0; i < 10; i++)
    {
        cout << sum[i] << ' ';
    }
    cout << '\n';
    cout << "prev ";
    for (int i = 0; i < 10; i++)
    {
        cout << previ[i] << ' ';
    }
    cout << '\n';
    cout << "len  ";
    for (int i = 0; i < 10; i++)
    {
        cout << len[i] << ' ';
    }
    cout << '\n';
    cout << "comb ";
    for (int i = 0; i < 10; i++)
    {
        cout << comb[i] << ' ';
    }*/
}
