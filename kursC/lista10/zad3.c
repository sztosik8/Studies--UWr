#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int tab[102][7];
long long st[65540];

void power(long long a, long long b)
{
    st[0] = 1;

    for (int i = 0; i < b; i++)
    {
        st[i + 1] = (st[i] * a) % 1000000;
    }
}
 
int main()
{
    int n;
    int n1 = scanf("%d", &n);
    n1++;

    for (int i = 1; i <= n; i++)
    {
        int stopien;
        int st1 = scanf("%d", &stopien);
        st1++;

        long long x;

        long long x2 = scanf("%lld", &x);
        x2++;

        long long ans = 0;
        power(x, stopien);

        for (int j = 0; j <= stopien; j++)
        {
            long long wsp;
            long long wsp1 = scanf("%lld", &wsp);
            wsp1++;
            ans += wsp * st[stopien - j];

        }
        if (ans < 0)
            ans *= -1;

        int j = 0;
        while (ans > 0 && j < 5)
        {
            tab[i][5 - j] = ans % 10;
            ans /= 10;
            j++;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= 5; i++)
            printf("%d", tab[j][i]);

        printf("\n");
    }

    return 0;
}
