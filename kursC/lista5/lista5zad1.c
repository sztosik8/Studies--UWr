// Katarzyna Trzos
// Lista 5 zadanie 1
// wypisywanie k-tej linijki spirali NxN
#include <stdio.h>

void spiralawiersz(int n, int k)
{
    if (n % 2 == 0)
    {
        if (k == 1)
        {
            for (int i = 0; i < n; i++)
                printf("%3d ", (n * n) - 3 * n + 3 + i); 
        }
        else if (k == n)
        {
            for (int i = 0; i < n; i++)
                printf("%3d ", (n * n) - i);
        }
        else
        {
            spiralawiersz(n - 1, k);
            printf("%3d ", n * n - 2 * n + k + 1);
        }
    }
    if (n % 2 == 1)
    {
        if (k == 1)
        {
            for (int i = 0; i < n; i++)
                printf("%3d ", (n * n) - n + 1 + i);
        }
        else if (k == n)
        {
            for (int i = 0; i < n; i++)
                printf("%3d ", (n * n) - i + 2 - 2 * n);
        }
        else
        {
            printf("%3d ", n * n - n - k + 2);
            spiralawiersz(n - 1, k - 1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        spiralawiersz(n, i);
        printf("\n");
    }
    return 0;
}