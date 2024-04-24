#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int tab[7];
int wart[65540];
//char kurde[504];

int main()
{
    char kurde[504];
    int n;
    int n1 = scanf("%d", &n);
    n1++;

    for (int i = 0; i < n; i++)
    {
        int stopien;
        int st1 = scanf("%d", &stopien);
        st1++;

        int arg;
        int ar1 = scanf("%d", &arg);
        ar1++;

        for (int j = 0; j < stopien + 1; j++)
        {
            long long wsp;
            long long wsp1 = scanf("%lld", &wsp);
            wsp1++;
            wart[stopien - j] = wsp;
        }
        long long ans=0;
        long long pot = 1;
        for (int j = 0; j < stopien + 1; j++)
        {
            ans += (wart[j] * pot) % 1000000;
            pot *= arg;
        }
        //printf("%lld\n", ans);
        if(ans<0)
            ans*=-1;

        int j=0;
        while (ans > 0 && j < 5)
        {
            tab[5 - j] = ans % 10;
            ans /= 10;
            j++;
        }
        for (int j = 1; j <= 5; j++)
        {
           
            int c=tab[j];

            kurde[(5*i)+j-1]=c+'0';
            kurde[(5*i)+j-1]='0';
            tab[j]=0;
        }
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=5; j++)
        {
            printf("%c", kurde[(5*i)+j-1]);
        }
        printf("\n");
    }

    return 0;
}
