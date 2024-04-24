#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

long long a[N], b[N];

long long price(long long k, int n)
{
    for (int i = 1; i <= n; i++)
        b[i - 1] = a[i] + (i * k);

    sort(b, b + n);

    long long p = 0;
    for (int i = 0; i < k; i++)
        p += b[i];

    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    long long high = n, low = 0, ans = 0, cost = 0;

    while (high >= low)
    {
        long long mid = (low + high) / 2;
        long long k = price(mid, n);

        if (k == m)
        {
            cout << mid << " " << m << endl;
            return 0;
        }

        if (k > m)
            high = mid - 1;
        else
            low = mid + 1, ans = mid, cost = k;
    }

    cout << ans << " " << cost << endl;

    return 0;
}
