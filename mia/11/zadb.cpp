#include <iostream>
#include <algorithm>

using namespace std;

int a[200000], c[200001] = {0};

int main()
{
    int n, q, l, r;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    while (q--)
    {
        cin >> l >> r;
        c[l-1] += 1;
        c[r] -= 1;
    }
    for (int i = 1; i < n; ++i)
    {
        c[i] += c[i-1];
    }

    sort(a, a + n);
    sort(c, c + n);
    long long answer = 0;
    for (int i = 0; i < n; ++i)
    {
        answer += static_cast<long long>(a[i]) * static_cast<long long>(c[i]);
    }
    cout << answer << endl;
    return 0;
}
