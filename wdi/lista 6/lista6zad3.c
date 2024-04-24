#include <stdio.h>

int tab[100005];

void babelki(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int x = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = x;
            }
        }
    }
}

int main()
{
    int n, el;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &el);

        tab[i] = el;
    }

    babelki(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}