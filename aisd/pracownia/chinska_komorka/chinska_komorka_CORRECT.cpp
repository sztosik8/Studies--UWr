/*
Katarzyna Trzos
Alorytmy i struktury danych
Pracownia 4
Chinska komorka
*/
#include <iostream>
using namespace std;
int lit[10003];
long long post[10003];
long long dp[103][10002];
int opt_ind[102][10003];
long long prev_values[100003];
long long new_values[100003];

int set_first_cost(int l)
{
    int ans = lit[1];
    for (int i = 1; i <= l; i++)
    {
        // cout << i * lit[i+1] << '\n';
        ans += i * lit[i + 1];
    }
    return ans;
}

int przesun_palke_na_ind(long long val, int ind)
{
    return (val - post[ind] + ind * lit[ind]);
}

long long find_opt_val(int palka, int ind)
{
    long long co_odejmuje = post[ind];
    // long long min_val = dp[palka][ind - 1] - co_odejmuje;
    long long min_val_opt = prev_values[ind - palka - 2] - co_odejmuje;

    int indeks_min = ind - 1;
    // cout << " NOWA WARTOSC POCZATKOWA tablica  " << prev_values[ind - palka - 2] << " - " << co_odejmuje << " = " << min_val_opt << '\n';
    //  cout << " NOWA WARTOSC POCZATKOWA  " << dp[palka][ind - 1] << " - " << co_odejmuje << " = " << min_val << '\n';
    for (int i = ind - 2; i > palka; i--)
    {
        co_odejmuje += post[ind];
        long long new_val = prev_values[i - palka - 1] - co_odejmuje;
        // long long new_val_opt = dp[palka][i] - co_odejmuje;
        // cout << "nowa wartosc_opt  " << prev_values[i - palka - 1] << " - " << co_odejmuje << " = " << new_val << '\n';
        // cout << "nowa wartosc  " << dp[palka][i] << " - " << co_odejmuje << " = " << new_val << '\n';
        if (new_val < min_val_opt)
        {
            min_val_opt = new_val;
            indeks_min = i;
        }
    }
    new_values[ind - palka - 2] = min_val_opt;
    // cout << new_values[ind - palka - 2] << '\n';*/

    return min_val_opt;
}
long long find_opt_val_fast(int palka, int ind)
{
    if (ind - palka - 2 == 0)
    {
        new_values[ind - palka - 2] = prev_values[ind - palka - 2] - post[ind];
    }
    else
    {
        cout << "wartosc obok  " << prev_values[ind - palka - 2] - post[ind] << " wartosc min z poprzedniej pozycji  " << prev_values[ind - opt_ind[palka][ind - 1]] << '\n';
        new_values[ind - palka - 2] = min(prev_values[ind - palka - 2] - post[ind], prev_values[palka + 1 - opt_ind[palka][ind - 1]] - post[ind] * (opt_ind[palka][ind - 1]));
    }
    return new_values[ind - palka - 2];
}

int find_opt_ind(int ind, int rozm_tab)
{
    int co_odejmuje = post[ind];
    long long min_val_opt = prev_values[rozm_tab - 1] - co_odejmuje;

    long long new_val;
    int jak_daleko = 1;

    for (int i = 2; i <= rozm_tab; i++)
    {
        co_odejmuje += post[ind];
        new_val = prev_values[rozm_tab - i] - co_odejmuje;
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

    for (int i = 1; i <= l; i++)
    {
        int f;
        cin >> f;
        lit[i] = f;
    }
    // setting postorder array
    for (int i = l; i > 0; i--)
    {
        post[i] = post[i + 1] + lit[i];
    }

    // uzupelnienie dp[1]    ----------------------------
    dp[1][2] = set_first_cost(l);
    int ile_elem = l - k + 1;
    prev_values[0] = set_first_cost(l);
    opt_ind[1][2] = 1;

    for (int i = 2; i <= l - k + 1; i++)
    {
        dp[1][i + 1] = przesun_palke_na_ind(dp[1][i], i);
    }

    for (int i = 1; i < ile_elem; i++)
    {
        prev_values[i] = przesun_palke_na_ind(prev_values[i - 1], i + 1);
        opt_ind[1][i + 2] = i + 1;
    }

    //---------------------------------------------------

    for (int i = 0; i < l - k + 1; i++)
    {
        cout << prev_values[i] << ' ';
    }
    cout << '\n';

    for (int i = 2; i <= k - 1; i++)
    {
        for (int j = 1; j <= ile_elem; j++)
        {
            dp[i][j + i] = find_opt_val(i - 1, j + i);
            opt_ind[i][j + i] = find_opt_ind(i + j, j);
        }
        for (int r = 0; r < l - k + 1; r++)
        {
            prev_values[r] = new_values[r];
            // cout << prev_values[r] << ' ';
        }
        // cout << '\n';
    }

    cout << '\n';
    cout << "wartosci " << '\n';
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j <= l; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
        cout << '\n';
    }
    cout << '\n';

    cout << "indeksy  " << '\n';
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j <= l; j++)
        {

            cout << opt_ind[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    cout << "prev " << '\n';
    for (int i = 0; i < l - k + 1; i++)
    {
        cout << prev_values[i] << ' ';
    }
    cout << '\n';

    if (k == 1)
    {
        cout << prev_values[ile_elem - 1] << '\n';
        cout << l << '\n';
    }
    else
    {
        cout << "tablica prev " << '\n';
        long long ans = prev_values[0];
        int min_val_ind = 0;
        for (int r = 0; r < ile_elem; r++)
        {
            cout << prev_values[r] << ' ';
            if (prev_values[r] < ans)
            {
                min_val_ind = r;
                ans = prev_values[r];
            }
        }
        cout << '\n';

        cout << ans << '\n';

        cout << '\n';

        // cout << l - k - iterator + 1 << ' ';

        // cout << "iterator " << iterator << '\n';
        // cout << "palka " << palka << '\n';

        // prev_values[0] = ile_elem - min_val_ind;
        // cout << "l " << l << " min_val_ind " << min_val_ind + k << '\n';
        prev_values[0] = l - min_val_ind - k;
        l -= prev_values[0];

        int palka = k - 1;
        int i = 1;
        while (i <= k - 1)
        {
            // cout << "komorka z ktorej odczytuje " << palka << " " << l + 1 << '\n';
            // cout << " i jej wartosc " << opt_ind[palka][l + 1] << '\n';
            prev_values[i] = opt_ind[palka][l + 1];
            l -= opt_ind[palka][l + 1];
            palka--;
            i++;
        }
        i--;
        while (i >= 0)
        {
            cout << prev_values[i] << ' ';
            i--;
        }
    }
}

/* TESTY
1 6 1 1 1 1 1 1    ----> 21   6
2 6 1 1 1 1 1 1    ----> 12    3 3
3 6 1 1 1 1 1 1    ----> 9     2 2 2
4 6 1 1 1 1 1 1    ----> 8     1 1 2 2
5 6 1 1 1 1 1 1    ----> 7     1 1 1 1 2
6 6 1 1 1 1 1 1    ----> 6     1 1 1 1 1 1
3 6 3 4 3 1 1 4    ----> 23    2 3 1
2 4 3 1 1 1        ----> 8     2 2
5 6 2 2 2 2 2 2    ----> 14    1 1 1 1 2
4 10 3 1 2 5 4 2 1 3 6 7 -> 56  3 4 2 1
5 10 3 1 2 5 4 2 1 3 6 7 -> 49 3 1 3 2 1
3 7 1 1 1 1 1 1 1023 --> 1035  3 3 1


3 400
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
