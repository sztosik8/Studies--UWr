#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();

    long long ans = 0;
    int ile_przed = 0;
    int co_przed = 0;
    for (int i = 0; i < len; i++)
    {
        int dig = s[i] - 48;
        // cout<<dig<<'\n';
        if (dig % 4 == 0)
        {
            ans++;
            // cout<<dig<<'\n';
        }
        int new_num = co_przed * 10 + dig;

        if (new_num % 4 == 0)
        {
            // ans++;
            ans += ile_przed;
            // cout<<new_num<<'\n';
        }
        co_przed = dig;
        ile_przed++;
    }
    cout << ans << '\n';
}
