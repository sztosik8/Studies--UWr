#include <iostream>
using namespace std;
int lit[10003];
int post[10003];
int opt_ind[102][10003];
long long prev_values[10003];
long long new_values[10003];

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
int find_opt_ind_fast(int ind, int rozm_tab)
{
    long long first_val = prev_values[rozm_tab - 1] - post[ind];
    int jak_daleko = 1;

    if (rozm_tab != 1)
    {
        int k = opt_ind[ind - rozm_tab][ind - 1] + 1;

        long long new_val = prev_values[rozm_tab - k] - k * post[ind];
        if (first_val > new_val) // ? =
        {
            first_val = new_val;
            jak_daleko = k;
        }
    }

    new_values[rozm_tab - 1] = first_val;

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
    prev_values[0] = set_first_cost(l);
    opt_ind[1][2] = 1;

    for (int i = 1; i < ile_elem; i++)
    {
        prev_values[i] = przesun_palke_na_ind(prev_values[i - 1], i + 1);
        opt_ind[1][i + 2] = i + 1;
    }

    for (int i = 2; i <= k - 1; i++)
    {
        for (int j = 1; j <= ile_elem; j++)
        {
            opt_ind[i][j + i] = find_opt_ind_fast(i + j, j);
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
        prev_values[0] = l - min_val_ind - k + 1;
        l -= prev_values[0];

        int palka = k - 1;
        int i = 1;
        while (i <= k - 1)
        {
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