#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 300003;
char s[MAXN];

int main()
{
    int n, x, y, cnt = 0;
    cin >> n >> x >> y >> s;
    for (int i = 0, j = 0; i < n; i = j)
    {
        while (j < n && s[i] == s[j])
            j++; 
        if (s[i] == '0')
            cnt++; 
    }
    ll ans;
    if (!cnt)
        ans = 0;
    else if (x < y)
        ans = x * (cnt - 1ll) + y;
    else
        ans = 1ll * y * cnt;
    cout << ans;
    return 0;
}
