/*
 * Katrzyna Trzos
 * Lista 1 zadanie 4
 * gcc zad4.c
 */
#include <stdio.h>
#include <stdlib.h>

void tabliczka(float x1, float x2, float y1, float y2, float skok)
{
    int row = ((x2 - x1) / skok) + 1;
    int col = ((y2 - y1) / skok) + 1;

    if ((row-1) * skok == (x2 - x1))
        row--;
    if ((col-1) * skok == (y2 - y1))
        col--;

    printf("        ");
    for (int i = 0; i < col; i++)
        printf("%11.4f", y1 + (i * skok));

    printf("\n");

    for (int i = 0; i < row; i++)
    {
        float y = y1 + i * skok;
        printf("%7.4f:", y);
        for (int j = 0; j < col; j++)
        {
            float x = x1 + (j * skok);
            printf("%11.4f", x * y);
        }
        printf("\n");
    }
}

int main()
{
    tabliczka(0.2, 1.3, 0.2, 3.14, 0.3);
     //tabliczka(1, 10, 1, 10, 1);
    return 0;
}
