#include <stdio.h>
#include <math.h>

int main()
{
    int d;
    long long d2 = scanf("%d", &d);
    d2 = d * d;

    long long i;

    i = floor(sqrt(d2 / 3));

    // printf("%lld\n", d2 / 3);
    // printf("%f\n", sqrt(d2 / 3));
    // printf("%lld\n", i);

    for (long long c = i; c > 0; c--)
    {
        long long c2 = (c * c);

        for (long long b = c; (b * b) + (b * b) + c2 <= d2; b++)
        {
            long long b2 = (b * b);
            long long a2 = d2 - b2 - c2;
            double a= sqrt(a2);
            float h= sqrt(a2);


            if (a - floor(a) == 0)
            {
                printf("%.0lf %lld %lld \n", a, b, c);
                return 0;
            }

            // for (long long a = b; (a*a)+ c2 + b2 <= d2; a++)
            // {
            //     long long a2 = (a * a);

            //     if (a2 + b2 + c2 == d2)
            //     {
            //         printf("%lld %lld %lld \n", a, b, c);
            //         return 0;
            //     }
            // }
        }
    }
    printf("BRAK\n");
}