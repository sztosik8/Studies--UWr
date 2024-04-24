#include <stdio.h>

int mapa[203][203];

void wpisz_do_tablicy(int w, int h);

int main()
{

    int w, h;
    scanf("%d %d", &w, &h);
    wpisz_do_tablicy(w, h);

    int n;

    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void wpisz_do_tablicy(int w, int h)
{
    char pole;
    for (int i = 0; i < h; i++)
    {
        int j = 0;
        pole = getchar();
        while (j < w)
        {
            if (pole != 32 && pole != 10)
            {
                mapa[i][j] = pole;
                j++;
            }
            pole = getchar();
        }
    }

    return;
}