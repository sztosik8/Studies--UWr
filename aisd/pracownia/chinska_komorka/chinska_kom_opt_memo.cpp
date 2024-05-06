/*
Katarzyna Trzos
Alorytmy i struktury danych
Pracownia D
Liczby
wersja ze zoptymalizowana pamiecia
*/
#include <iostream>
using namespace std;

int ans_tab[10005];
int opt_ind[102][10005];
long long prev_values[10005];
long long new_values[10005];
int lit[10005];
int post[10005];

int find_opt_ind(int rozm_tab, int ind)
{
    long long min_val_opt = prev_values[rozm_tab - 1] - post[ind];

    long long new_val;
    int jak_daleko = 1;

    for (int i = 2; i <= rozm_tab; i++)
    {
        new_val = prev_values[rozm_tab - i] - i * post[ind];
        if (new_val <= min_val_opt)
        {
            min_val_opt = new_val;
            jak_daleko = i;
        }
    }
    new_values[rozm_tab - 1] = min_val_opt;
    return jak_daleko;
}

int main()
{
    int k, l;
    cin >> k >> l;

    for (int i = l; i > 0; i--)
    {
        post[i] = post[i + 1] + lit[i];
    }
    opt_ind[1][2] = 1;

    int ile_elem = l - k + 1;

    for (int i = 1; i <= l; i++)
    {
        int f;
        cin >> f;
        lit[i] = f;
    }
    prev_values[0] = lit[1];
    int ans = lit[1];

    for (int i = 1; i <= l; i++)
    {
        ans += i * lit[i + 1];
    }

    for (int i = 1; i < ile_elem; i++)
    {
        prev_values[i] = prev_values[i - 1] - post[i + 1] + (i + 1) * lit[i + 1];
        opt_ind[1][i + 2] = i + 1;
    }

    for (int i = 2; i <= k - 1; i++)
    {
        for (int j = 1; j <= ile_elem; j++)
        {
            opt_ind[i][j + i] = find_opt_ind(j, i + j);
        }
        for (int r = 0; r < l - k + 1; r++)
        {
            prev_values[r] = new_values[r];
        }
    }

    if (k == 1)
    {
        cout << prev_values[ile_elem - 1] << '\n';
        cout << l << '\n';
    }
    else
    {
        long long ans = prev_values[0];
        int min_val_ind = 0;
        for (int r = 0; r < ile_elem; r++)
        {
            if (prev_values[r] < ans)
            {
                min_val_ind = r;
                ans = prev_values[r];
            }
        }
        cout << ans << '\n';

        int temp = l;
        ans_tab[0] = temp - min_val_ind - k + 1;
        temp -= ans_tab[0];

        int palka = k - 1;
        int i = 1;
        while (i <= k - 1)
        {
            ans_tab[i] = opt_ind[palka][temp + 1];
            temp -= opt_ind[palka][temp + 1];
            palka--;
            i++;
        }
        i--;
        for (; i >= 0; i--)
        {
            cout << ans_tab[i] << ' ';
        }
    }
}