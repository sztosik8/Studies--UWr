// Katarzyna Trzos
// Lista 3 zadanie
//

#include <stdio.h>

int zagn = 0;

void liczbanaw(char znak)
{
    while (znak != EOF && zagn >= 0)
    {
        if (znak == '{')
        {
            printf("%c\n", znak);
            zagn++;
        }
        if (znak == '}')
        {
            printf("\n");
            if (zagn >= 4)
            {
                for (int i = 0; i < zagn - 4; i++)
                {
                    printf(" ");
                }
            }
            printf("%c\n", znak);

            zagn--;
        }
        if (znak == '\n')
        {
            for (int i = 0; i < zagn * 4; i++)
            {
                printf(" ");
            }
        }
        znak = getchar();
    }
    return;
}

int main()
{

    char znak;
    znak = getchar();

    liczbanaw(znak);

    printf("\n");

    return 0;
}