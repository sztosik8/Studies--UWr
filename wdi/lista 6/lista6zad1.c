#include <stdio.h>
int a[] = {1, 3, 4, 5, 8, 9, 10, 6};

int binary(int i)
{
    int x = a[i];
    int lewy = 0;
    int prawy = i - 1;
    while (lewy < prawy)
    {
        int k = (lewy + prawy) / 2; // dzielenie całkowite!
         if (a[k] == x)
            printf("%d %d \n", lewo, prawo);
        if (a[k] < x)
            lewy = k ;
        else
            prawy = k ;
    }
    return -1;
}

int znajdzI(int n, int x)
{
    int b, e, s;
    b = 0;
    e = n - 1;
    while (b <= e)
    {
        s = (b + e) / 2;
        if (a[s] == x)
            return s;
        if (x < a[s])
            e = s - 1;
        else
            b = s + 1;
    }
    return b;
}

int main()
{
    int liczba;

    scanf("%d", &liczba);
    a[7]=liczba;

    printf("%d\n", znajdzI(7, 7));
}
