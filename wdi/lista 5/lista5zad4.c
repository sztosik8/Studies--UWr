#include <stdio.h>

int main()
{
    int a = 1, b = 1, c = 1, d=3;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 3; i++)
    {
        a = b;
        b = c;
        c = d;
        d = a + b + c;
    }
    printf("%d\n", d);
}