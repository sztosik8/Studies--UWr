#include <stdio.h>

int t1(int n)
{
    if (n == 1)
        return 1;
    else
    {
        return t1(n - 1) + n;
    }
}

int t2(int n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
    {
        return t2(n / 2) + 1;
    }
    else
    
        return t2((n+1) / 2) + 1;
        return t2((n + 1) / 2) + 1;
}

int t3(int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 0)
    {
        return 2 * t3(n / 2) + 1;
    }
    return t3((n - 1) / 2) + 1 + t3((n + 1) / 2) + 1;
}

int main()
{

    printf("zad 1  T(16)=%d\n", t1(16));
    printf("zad 2  T(16)=%d\n", t2(16));
    printf("zad 3  T(16)=%d\n", t2(16));
}