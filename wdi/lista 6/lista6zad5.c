#include <stdio.h>

int s[10000];

void pierwsze(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (s[i] == 1)
        {
            int j = 2;
            while (i * j <= n)
            {
                s[i * j] = 0;
                j++;
            }
        }
    }
}

int main()
{

    int n;

    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        s[i] = 1;
    }

    pierwsze(n);

    for (int i = 1; i < n; i++)
    {
        if (s[i])
        {
            printf("%d \n", i);
        }
        // printf("%d [%d] \n", i, s[i]);
    }
}