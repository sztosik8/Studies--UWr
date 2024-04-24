#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ilea(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
            ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;

        int sa = s.length();
        int ta = ilea(t);
        long long ans=pow(2, sa);

        if (t == "a")
            cout << 1 << '\n';
        else 
        {
            if (ta != 0 )
                cout << -1 << '\n';
            else
                cout << ans << '\n';
        }
    }
}
