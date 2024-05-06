/*
Katarzyna Trzos
Alorytmy i struktury danych
Pracownia D
Liczby
*/
#include <iostream>
using namespace std;
int lit[10003];
int post[10003];
int opt_ind[102][10003]; // opt_ind[i][j] tablica trzymajaca ile pozycji wczensiej stoi optymalna palka i-1, dla palki i w j-tym miejscy
long long dp_val[103][10002];

int set_first_cost(int l)
{
    int ans = lit[1];
    for (int i = 1; i <= l; i++)
    {
        ans += i * lit[i + 1];
    }
    return ans;
}

int przesun_palke_na_ind(long long val, int ind)
{
    return (val - post[ind] + ind * lit[ind]);
}

int find_opt_ind_array(int ind, int rozm_tab)
{
    int co_odejmuje = post[ind];
    long long min_val_opt = dp_val[ind - rozm_tab - 1][ind - 1] - co_odejmuje;

    long long new_val_opt;
    int jak_daleko = 1;
    // int k = opt_ind[ind - rozm_tab][ind - 1] + 1;

    for (int i = 2; i <= rozm_tab; i++)
    {
        co_odejmuje += post[ind];
        new_val_opt = dp_val[ind - rozm_tab - 1][ind - i] - co_odejmuje;
        if (new_val_opt <= min_val_opt)
        {
            min_val_opt = new_val_opt;
            jak_daleko = i;
        }
    }
    dp_val[ind - rozm_tab][ind] = min_val_opt;
    return jak_daleko;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, l;
    cin >> k >> l;

    for (int i = 1; i <= l; i++)
    {
        int f;
        cin >> f;
        lit[i] = f;
    }

    for (int i = l; i > 0; i--)
    {
        post[i] = post[i + 1] + lit[i];
    }
    int ile_elem = l - k + 1;

    dp_val[1][2] = set_first_cost(l);
    opt_ind[1][2] = 1;

    for (int i = 1; i < ile_elem; i++)
    {
        dp_val[1][i + 2] = przesun_palke_na_ind(dp_val[1][i + 1], i + 1);
        opt_ind[1][i + 2] = i + 1;
    }

    for (int i = 2; i <= k - 1; i++)
    {
        for (int j = 1; j <= ile_elem; j++)
        {
            opt_ind[i][j + i] = find_opt_ind_array(i + j, j);
        }
    }

    if (k == 1)
    {
        cout << dp_val[1][l + 1] << '\n';
        cout << l << '\n';
    }
    else
    {
        long long ans = dp_val[k - 1][k];
        int min_val_ind = k;
        for (int r = k + 1; r <= l; r++)
        {
            if (dp_val[k - 1][r] < ans)
            {
                min_val_ind = r;
                ans = dp_val[k - 1][r];
            }
        }
        cout << ans << '\n';
        dp_val[k][0] = l - min_val_ind + 1;
        l -= dp_val[k][0];

        int palka = k - 1;
        for (int i = 0; palka >= 0; i++)
        {
            dp_val[k][i + 1] = opt_ind[palka][l + 1];
            l -= opt_ind[palka][l + 1];
            palka--;
        }

        for (int i = k - 1; i >= 0; i--)
        {
            cout << dp_val[k][i] << ' ';
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
4 10 3 1 2 5 4 2 1 3 6 7  -> 56  3 4 2 1
5 10 3 1 2 5 4 2 1 3 6 7  -> 49 3 1 3 2 1
3 7 1 1 1 1 1 1 1023     --> 1035  3 3 1

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
--> 26867 133 133 134
*/