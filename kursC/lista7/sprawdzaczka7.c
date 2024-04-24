#include <stdio.h>

int slowa[1002][1002];
int litery[27];

int main()
{
    int n, k;

    int no = scanf("%d", &n);
    int ko = scanf("%d", &k);
    no++;
    ko++;

    char lit = getchar();
    // printf("\n");

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        lit = getchar();

        while ('a' <= lit && lit <= 'z')
        {
            // printf("%c", lit);
            slowa[i][j] = lit;
            // printf("%c", slowa[i][j]);
            //  printf("%d ", i);
            //  printf("%d\n", j);

            if (i == n - 1 && j == k - 1)
            {
                break;
            }
            lit = getchar();
            j++;
        }
        // printf("\n");
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            litery[slowa[j][i] - 'a']++;
        }
        for (int j = 0; j < n; j++)
        {
            // printf("%d ", slowa[j][i]-'a');
            slowa[j][k] += litery[slowa[j][i] - 'a'];
            if (litery[slowa[j][i] - 'a'] == 1)
            {
                slowa[j][k + 1]++;
            }
            // printf("%d ", uni[j][i]);
        }

        for (int j = 0; j < 27; j++)
        {
            litery[j] = 0;
        }
        // printf("\n");
    }

    int min = -1;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("%d ", slowa[i][k]);
        if (slowa[i][k+1] > min)
        {
            min = slowa[i][k+1];
            
            ind = i;
        }
        //printf("%d", slowa[i][k+1]);
    }
    // printf("%d\n", min);
    // printf("%d\n", minn); 

    for (int i = 0; i < k; i++)
    {
        printf("%c", slowa[ind][i]);
    }

    printf("\n%d\n", slowa[ind][k + 1]);

    return 0;
}
