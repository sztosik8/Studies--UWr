#include <stdio.h>
#include <stdlib.h>

int tab[1000][1000];

int droga(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 & j==0) j++;
            if(i==0) tab[i][j]+=tab[i][j+1];
            else if(j==0) tab[i][j]+=tab[i-1][j];
            else tab[i][j]+= min(tab[i-1][j], tab[i][+j]);         
        }
    }

}



int main()
{
    int n;
    int x;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &x);
            tab[i][j]=x;
        }
    }
    scanf("%d", &n);
    //init(n);

    //printf("%d\n", queens(n));
}