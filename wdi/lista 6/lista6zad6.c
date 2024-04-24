#include <stdio.h>
int pier[10003];
int s[10003];

void prim()
{
    for (int i = 2; i < 10000; i++)
    {
        if (pier[i] == 0)
        {
            int j = 2;
            while (i * j <= 10000)
            {
                pier[i * j] = 1;
                j++;
            }
        }
    }
    int j = 0;

    for (int i = 2; i < 10000; i++)
    {

        if (pier[i] == 0)
        {
            pier[j] = i;
            j++;
        }
    }
}

void pierwsze(int m, int n)
{
    for (int i = m; i <= n; i++)
    {
        for (int j = 0; pier[j] * pier[j] <= i; j++)
        {
            if (i % pier[j] == 0)
            {
                s[i - m] = 1;
                break;
            }
        }
    }
}

int main()
{
    int n, m;

    scanf("%d", &m);
    scanf("%d", &n);

    prim();
    pierwsze(m, n);
    int ans=0;

    for (int i = 0; i < n - m + 1; i++)
    {

        if(s[i]==0) ans++;
        //printf("%d - %d\n", i + m, s[i]); // pierwsza 0
    }
    printf("%d\n", ans);
}
