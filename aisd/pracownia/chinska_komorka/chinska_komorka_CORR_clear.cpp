
#include <iostream>
using namespace std;
int lit[10003];
int post[10003];
int opt_ind[102][10003];
long long dp_val[103][10002];
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
    // cout << val << '-' << post[ind] << '+' << ind << "*" << lit[ind] << '=' << (val - post[ind] + ind * lit[ind]) << '\n';
    return (val - post[ind] + ind * lit[ind]);
}

int find_opt_ind(int ind, int rozm_tab)
{
    int co_odejmuje = post[ind];
    long long min_val_opt = prev_values[rozm_tab - 1] - co_odejmuje;
    cout << "first value " << min_val_opt << '\n';

    long long new_val;
    int jak_daleko = 1;
    int k = opt_ind[ind - rozm_tab][ind - 1] + 1;

    for (int i = 2; i <= k; i++)
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
int find_opt_ind_array(int ind, int rozm_tab)
{
    int co_odejmuje = post[ind];
    // long long min_val_opt = prev_values[rozm_tab - 1] - co_odejmuje;
    long long min_val_opt = dp_val[ind - rozm_tab - 1][ind - 1] - co_odejmuje;
    // cout << "first value " << min_val_opt << '\n';

    long long new_val_opt;
    int jak_daleko = 1;
    int k = opt_ind[ind - rozm_tab][ind - 1] + 1;

    for (int i = 2; i <= k; i++)
    {
        co_odejmuje += post[ind];
        // new_val = prev_values[rozm_tab - i] - co_odejmuje;
        new_val_opt = dp_val[ind - rozm_tab - 1][ind - i] - co_odejmuje;
        // cout<<"new_value "<<
        if (new_val_opt <= min_val_opt)
        {
            min_val_opt = new_val_opt;
            jak_daleko = i;
        }
    }
    dp_val[ind - rozm_tab][ind] = min_val_opt;
    // new_values[rozm_tab - 1] = min_val_opt;
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
    //
    dp_val[1][2] = set_first_cost(l);
    //
    prev_values[0] = set_first_cost(l);
    opt_ind[1][2] = 1;

    for (int i = 1; i < ile_elem; i++)
    {
        //
        dp_val[1][i + 2] = przesun_palke_na_ind(dp_val[1][i + 1], i + 1);
        //
        prev_values[i] = przesun_palke_na_ind(prev_values[i - 1], i + 1);
        opt_ind[1][i + 2] = i + 1;
    }

    for (int i = 2; i <= k - 1; i++)
    {
        for (int j = 1; j <= ile_elem; j++)
        {
            opt_ind[i][j + i] = find_opt_ind_array(i + j, j);
        }
        for (int r = 0; r < l - k + 1; r++)
        {
            prev_values[r] = new_values[r];
        }
    }
    /*
         for (int r = 0; r < ile_elem; r++)
            {
                dp_val[2][3+r]=prev_values[r];

            }
            */

    cout << '\n';
    cout << "wartosci " << '\n';
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j <= l; j++)
        {
            cout << dp_val[i][j] << ' ';
        }
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

    for(int i=0; i<l+2; i++){
        cout<<i<<':'<<prev[1][i]<<'\n';
    }

    if (k == 1)
    {
        cout << prev_values[ile_elem - 1] << '\n';
        cout << l << '\n';
    }
    else
    {
        long long ans = dp_val[k - 1][k];
        cout << " ans  " << ans << ' ' << k << '\n';
        int min_val_ind = k;
        for (int r = k + 1; r <= l; r++)
        {
            cout << dp_val[k - 1][r] << ' ' << r << '\n';
            if (dp_val[k - 1][r] < ans)
            {
                min_val_ind = r;
                ans = dp_val[k - 1][r];
            }
            /*
            if (prev_values[r] < ans)
            {
                min_val_ind = r;
                ans = prev_values[r];
            }*/
        }
        cout << '\n';
        cout << ans << '\n';
        dp_val[k][0] = l - min_val_ind + 1;
        // prev_values[0] = l - min_val_ind - k + 1;
        // l -= prev_values[0];
        l -= dp_val[k][0];
        // cout << " l " << l;

        int palka = k - 1;
        for (int i = 0; palka >= 0; i++)
        {
            cout << l << '\n';
            //cout << "opt_ind " << opt_ind[palka][l + 1]<<'\n';
            dp_val[k][i + 1] = opt_ind[palka][l + 1];
            l -= opt_ind[palka][l + 1];
             palka--;
        }

        for (int i = k-1; i >=0; i--)
        {
            cout << dp_val[k][i] << ' ';
        }
    }
}