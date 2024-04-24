#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int a[100002];

int index_bi(int x, int start, int end, int n)
{
    if (start > end)
    {
        if (start > n)
        {
            return n;
        }
        return start;
    }

    int mid = start + (end - start) / 2;

    if (a[mid] > x)
    {
        // Element może być w lewej części tablicy.
        return index_bi(x, start, mid - 1, n);
    }
    else
    {
        // Element może być w prawej części tablicy.
        return index_bi(x, mid + 1, end, n);
    }
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a[i] = x;
    }

    bubbleSort(a, n);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        int p = index_bi(x, 0, n, n);
        cout << p << ' ';
    }
}