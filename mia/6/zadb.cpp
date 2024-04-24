#include <iostream>
#include <string>
using namespace std;

bool if3(string ciag)
{
    int sum = 0;
    int zero = 0;
    int parz = 0;

    // cout << ciag << '\n';
    for (int i = 0; i < ciag.length(); i++)
    {
        int k = ciag[i] - '0';
        if (k % 2 == 0 && k != 0)
            parz++;
        if (k == 0)
        {
            zero++;
        }
        // cout << k << '\n';
        sum += k;
    }
    // cout << "sum " << sum << " zero " << zero << " parzyste " << parz << '\n';

    if (sum == 0)
    {
        return true;
    }

    if ((sum % 3 == 0) && parz > 0 && zero > 0)
    {
        return true;
    }
    if (sum % 3 == 0 && parz == 0 && zero > 1)
        return true;

    return false;
}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string ciag;
        cin >> ciag;
        if (if3(ciag) == 1)
            cout << "red" << '\n';
        else
            cout << "cyan" << '\n';
    }

    return 0;
}
