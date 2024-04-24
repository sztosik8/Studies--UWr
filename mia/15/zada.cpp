#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300030;
char s[MAXN];

int main()
{
    int n, x, y, cnt = 0;
    scanf("%d%d%d%s", &n, &x, &y, s);
    for (int i = 0, j = 0; i < n; i = j)
    {
        while (j < n && s[i] == s[j])
            j++; // 定位连续的0或1
        if (s[i] == '0')
            cnt++; // 计数连续的0
    }
    ll ans;
    if (!cnt)
        ans = 0;
    else if (x < y)
        ans = x * (cnt - 1ll) + y;
    else
        ans = 1ll * y * cnt;
    printf("%lld", ans);
}