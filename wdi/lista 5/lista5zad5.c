#include <stdio.h>

int T(int n, int m)
{
    if(m==0)
    {
        return n;
    }
    else if(n==0)
    {
        return m;
    }
    else
    {
        return T((n-1), m)+ 2 * T(n,(m-1));
    }
}

int main()
{
    int k, r;
    scanf("%d", &k);
    scanf("%d", &r);

    for(int i=0; i<=k; i++)
    {
        for(int j=0; j<=r; j++)
        {
            printf("%5d", T(i, j));

        }
        
        printf("\n");
    }
    
}