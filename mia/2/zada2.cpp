#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int n, a, b;
    cin >> n >> a >> b;
    int prev = 0;
    char seat;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> seat;

        if (seat == '.')
        {
            if (prev == 1 && b != 0)
            {
                b--;
                ans++;
                prev = 2;
            }
            else if (prev == 2 && a != 0)
            {
                a--;
                ans++;

                prev = 1;
            }
            else if (prev == 0)
            {
                if (a < b)
                {
                    prev = 2;
                    ans++;
                    b--;
                }
                else if (a > 0)
                {
                    prev = 1;
                    ans++;
                    a--;
                }
            }
            else
            {
                prev = 0;
            }
        }
        else
        {
            prev = 0;
        }
    }
    cout << ans << '\n';
}