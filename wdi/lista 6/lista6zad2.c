#include <stdio.h>

int tab[100003];

void selection(int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (tab[min] > tab[j])
                min = j;

            if (min != i)
            {
                int x = tab[min];
                tab[min] = tab[i];
                tab[i] = x;
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

    selection(n);

    for (int i = 0; i < n; i++)
        printf("%d ", tab[i]);

    return 0;
}