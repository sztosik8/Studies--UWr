#include <stdio.h>

typedef struct
{
    int godz;
    int min;
    int sec;

} time;

time wczytaj(char c, time a)
{
    a.sec = 0;
    a.min = 0;
    a.godz = 0;

    while ('0' <= c && c <= '9') // WCZYTANIE PIERWSZEGO CZASU
    {
        a.sec *= 10;
        a.sec += c - '0';
        c = getchar();
    }
    if (c == ':')
    {
        a.min = a.sec;
        a.sec = 0;
        c = getchar();
        while ('0' <= c && c <= '9')
        {
            a.sec *= 10;
            a.sec += c - '0';
            c = getchar();
        }
    }
    if (c == ':')
    {
        a.godz = a.min;
        a.min = a.sec;
        a.sec = 0;
        c = getchar();
        while ('0' <= c && c <= '9')
        {
            a.sec *= 10;
            a.sec += c - '0';
            c = getchar();
        }
    }

    return a;
}

void odp(long long x)
{
    if (x < 0)
    {
        printf("-");
        x *= -1;
    }
    if (x / 3600 != 0)
    {
        printf("%lld:", (x / 3600));
        x %= 3600;

        printf("%lld:", (x / 60));
        x %= 60;
        printf("%lld\n", x);
        return;
    }
    if (x / 60 != 0)
    {
        printf("%lld:", (x / 60));
        x %= 60;
        printf("%lld\n", x);
        return;
    }
    printf("%lld\n", x);
    return;
}

int main()
{

    char c;
    c = getchar();
    time a;
    time b;
    char operator;

    while ('0' <= c && c <= '9')
    {

        a = wczytaj(c, a);

        c = getchar();
        while (c == ' ')
            c = getchar();

        operator= c;

        c = getchar();

        while (c == ' ')
            c = getchar();

        b = wczytaj(c, b);

        //////zamiana na sekundy
        int one = 0;
        int two = 0;
        one = (a.godz * 3600) + (a.min * 60) + (a.sec);
        two = (b.godz * 3600) + (b.min * 60) + (b.sec);

        if (operator== '+')
        {
            int ans = one + two;
            odp(ans);
        }
        if (operator== '-')
        {
            int ans = one - two;
            odp(ans);
        }
        if (operator== '*')
        {
            int ans = one * two;
            odp(ans);
        }
        if (operator== '/')
        {
            int ans = one / two;
            odp(ans);
        }
        c = getchar();
    }
}