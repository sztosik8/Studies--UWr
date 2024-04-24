#include <stdio.h>

int gcd(int n, int m)
{
    int ilenp;
    if (!m)
    {
        return n;
    }

    if (n < m)
    {
        return gcd(m, n);
    }

    ilenp = n % 2 + m % 2;
    
    if (ilenp == 2)
    {
        return gcd(n - m, m);
    }

    if (!ilenp)
    {
        return 2 * gcd(n / 2, m / 2);
    }

    if (n % 2 == 0)
    {
        return gcd(n / 2, m);
    }

    else
    {
        return gcd(n, m / 2);
    }
}

int main()
{
}