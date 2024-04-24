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

        int sa = ilea(s);
        int ta = ilea(t);

        if (sa == 0)
            cout << 1 << '\n';
        else if (ta != 0 && t != "a")
            cout << -1 << '\n';
        else
        {
            if (t == "a")
                cout << 1 << '\n';
            else
                cout << pow(2, sa) << '\n';
        }
    }
}
