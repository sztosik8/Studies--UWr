#include <stdio.h>

long long poweri(int a, int b)
{
    int ile = 0;
    long long ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans *= a;
            ile++;
        }
        b /= 2;
        a *= a;
        ile++;
    }
    printf("ile mnozen %d \n", ile);
    return ans;
}


int main()
{
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);
    printf("%lld \n", poweri(n, m));

    return 0;
}