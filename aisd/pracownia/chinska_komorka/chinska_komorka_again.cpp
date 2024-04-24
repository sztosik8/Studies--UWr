/*
Katarzyna Trzos
Alorytmy i struktury danych
Pracownia 4
Chinska komorka
*/
#include <iostream>
using namespace std;
int lit[10003];
int ind[102];
int post[10003];
int ans;

int move(int it)
{
    int i = ind[it];
    int min_ind = i;
    int nexti = ind[it + 1];
    int previ = ind[it - 1];
    int prev_ans = ans;
    while (i + 1 < nexti)
    {
        int new_cost = prev_ans - (post[i] - post[nexti]);

        new_cost += (i - previ + 1) * lit[i];
        ind[it]++;
        prev_ans = new_cost;

        if (new_cost < ans)
        {
            ans = new_cost;
            min_ind = i + 1;
        }
        i++;
    }
    return min_ind;
}

void set_first_cost(int k, int l)
{
    for (int i = 1; i < k; i++)
    {
        ans += lit[i];
    }
    for (int i = 1; i <= l - k + 1; i++)
    {
        ans += i * lit[i + k - 1];
    }
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
    for (int i = l; i > 0; i--)
    {
        post[i] = post[i + 1] + lit[i];
    }

    for (int i = 0; i <= k - 1; i++)
    {
        ind[i] = i + 1;
    }
    ind[k] = l + 1;
    set_first_cost(k, l);
    // cout << ans;

    int ktor = k - 1;
    while (ktor > 0)
    {
        ind[ktor] = move(ktor);
        ktor--;
    }

    cout << ans << '\n';
    for (int i = 0; i < k; i++)
    {
        cout << ind[i + 1] - ind[i] << ' ';
    }
}