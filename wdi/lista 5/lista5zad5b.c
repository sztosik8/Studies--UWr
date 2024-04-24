#include <stdio.h>

int tab[100000];

int T(int n, int m)
{
    int ob;
    int lewo;
    for (int i = 0; i <= m; i++)
    {
        tab[i] = i;
        // printf("%d ", tab[i]);
    }

    for (int i = 0; i < n; i++)
    {
        lewo = i + 1;
        tab[0] = lewo;

        for (int j = 1; j <= m; j++)
        {

            ob = lewo * 2 + tab[j];
            tab[j] = ob;
            //printf("%d ", tab[j]);
            lewo = ob;
        }
        // printf("\n");
        
    }
    
    return tab[m];
}

int main()
{
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    printf("%d\n", T(n, m));
}