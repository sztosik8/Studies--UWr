#include <stdio.h>
char slowa[1000][1000];
int main()
{
    int n, k;
    int no = scanf("%d", &n);
    int ko = scanf("%d", &k);
     printf("%d\n", n);
     printf("%d", k);

    int lit;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &lit);

            // printf("%d", lit);
            // slowa[i][j] = lit;
            // printf("%c", slowa[i][j]);
            //printf("%d ", i);
            //  printf("%d\n", j);
        }

        // printf("\n");
    }

   

    return 0;
}
