#include <stdio.h>

int fibmod(int k, int r)
{
    int a = 1, b = 1, c = 2 % r;

    if (k == 1 || k == 0)
    {
        return b;
    }
    if (k == 2)
    {
        return c;
    }

    for (int i = 0; i < k - 2; i++)
    {
        a = b;
        b = c;
        c = (a + b) % r;
        printf("%d\n", c);
    }
    return c;
}

int main()
{
    int k, r;
    scanf("%d", &k);
    scanf("%d", &r);
    printf("%d\n", fibmod(k, r));
}