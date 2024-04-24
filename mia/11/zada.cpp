#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> tab(n + 1, 0);
    vector<bool> fallen(n + 1, false);

    int k = n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        tab[num] = 1;
        fallen[num] = true;

        while (k > 0 && fallen[k])
        {
            cout << k << ' ';
            k--;
        }
        cout << '\n';
    }

    return 0;
}
