#include <iostream>
#include <cmath>
using namespace std;

int tab[4003];
int len[4];

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    len[0] = a;
    len[1] = b;
    len[2] = c;

    bubbleSort(len, 3);

    int a1 = len[0];
    int b1 = len[1];
    int c1 = len[2];

    tab[a] = 1;
    tab[b] = 1;
    tab[c] = 1;

    if (n % a1 == 0)
    {
        cout << n / a1 << '\n';
        return 0;
    }

    for (int i = 0; i + c1 <= n; i++)
    {
        if (tab[i] > 0)
        {
            tab[i + c1] = max(tab[i + c1], tab[i] + 1);
        }
    }
    for (int i = 0; i + b1 <= n; i++)
    {
        if (tab[i] > 0)
        {
            tab[i + b1] = max(tab[i + b1], tab[i] + 1);
        }
    }
    for (int i = 0; i + a1 <= n; i++)
    {
        if (tab[i] > 0)
        {
            tab[i + a1] = max(tab[i + a1], tab[i] + 1);
        }
    }
    cout << tab[n] << '\n';
}