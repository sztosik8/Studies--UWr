// Katarzyna Trzos
// Lista 3 zadanie 1
// liczenie zagniezdzenia { }

#include <stdio.h>

int zageszczenie = 0;

void liczbanaw(char znak)
{
    while (znak != EOF && zageszczenie >= 0)
    {
        printf("%c", znak);
        if (znak == '{')
        {
            zageszczenie++;
        }
        if (znak == '}')
        {
            zageszczenie--;
        }
        if (znak != '{' && znak != '}')
        {
            if (znak == '\n')
            {
                printf("%d ", zageszczenie);
            }
        }
        znak = getchar();
        
    }
    return;
}

int main()
{
    printf("%d", 0);
    char znak;
    znak = getchar();
    liczbanaw(znak);

    printf("\n");

    return 0;
}