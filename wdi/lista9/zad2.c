#include <stdio.h>

int b[1000];

void init(int n)
{
    int i;
    for (i = 0; i < n; i++)
        b[i] = -1;
}
int isfree(int x, int y)
{
    int i;
    for (i = 0; i < x; i++)
        if (b[i] - i == y - x || b[i] + i == y + x || b[i] == y)
        {
            return 0;
        }
    return 1;
}
int queens(int n)
{
    int sum = 0; // sume

    int k = 1;
    b[0] = 0;
    while (k < n && k >= 0)
    {
        do
        {
            b[k]++;
        } while (b[k] < n && !isfree(k, b[k]));
        if (b[k] < n)
            k++;
        else
        {
            b[k] = -1;
            k--;
        }
        ////
        if (k == n)
        {
            sum++;

            b[k] = -1;
            k--;
        }
        /////
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    init(n);

    printf("%d\n", queens(n));
}