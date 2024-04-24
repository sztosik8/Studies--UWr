#include <stdio.h>

int b[1000];

int hetmany(int n, int k, int a[])
{
    if (k == n)
        return poprawne(a, n);
    for (int i = 0; i < n; i++)
    {
        a[k] = i;
        if (hetmany(n, k + 1, a))
            return 1;
    }
    return 0;
}

int poprawne(int a[], int n)
{
    return 0;
}

int main()
{
    int n, k, a;
    scanf("%d", &n);
    //init(n);

    printf("%d\n", hetmany(n, k, a));
}