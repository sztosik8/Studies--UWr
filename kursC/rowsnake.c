#include <stdio.h>

int obraz[1030][1030];
int obsikane[1030][1030];

int N;

void row()
{
    int ans = 0;
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (obraz[i][j] == 1)
            {
                count++;
            }
            else
            {
                if (ans < count)
                {
                    ans = count;
                }
                count = 0;
            }
        }
    }
    printf("%d ", ans);
}
void snake()
{
    int ans = 0;
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= N; j++)
            {
                if (obraz[i][j] == 1)
                {
                    count++;
                }
                else
                {
                    if (ans < count)
                    {
                        ans = count;
                    }
                    count = 0;
                }
            }
        }
        else
        {
            for (int j = N; j > 0; j--)
            {
                if (obraz[i][j] == 1)
                {
                    count++;
                }
                else
                {
                    if (ans < count)
                    {
                        ans = count;
                    }
                    count = 0;
                }
            }
        }
    }
    printf("%d ", ans);
}

int diagonal()
{
    int ans = 0;
    int count = 0;
    int i = 1, j = 1;

    while (i <= N && j <= N)
    {

        if (i == 1 || j == N)
        {
            if (obraz[i][j] == 1)
            {
                count++;
            }
            else
            {
                if (ans < count)
                {
                    ans = count;
                }
                count = 0;
            }

            if (i == 1)
            {
                j++;
                if (j == N + 1)
                {
                    j--;
                    i++;
                }
            }
            else
            {
                i++;
            }
            while (j != 1 && i != N)
            {

                if (obraz[i][j] == 1)
                {
                    count++;
                }
                else
                {
                    if (ans < count)
                    {
                        ans = count;
                    }
                    count = 0;
                }

                j--;
                i++;
            }
        }

        if (j == 1 || i == N)
        {

            if (obraz[i][j] == 1)
            {
                count++;
            }
            else
            {
                if (ans < count)
                {
                    ans = count;
                }
                count = 0;
            }
            if (i > N || j > N)
            {
                printf("%d\n", ans);
                return 0;
            }

            if (j == 1)
            {
                i++;
                if (i == N + 1)
                {
                    i--;
                    j++;
                }
            }
            else
            {
                j++;
            }

            while (j != N && i != 1)
            {
                if (obraz[i][j] == 1)
                {
                    count++;
                }
                else
                {
                    if (ans < count)
                    {
                        ans = count;
                    }
                    count = 0;
                }
                if (i > N || j > N)
                {
                    printf("%d\n", ans);
                    return 0;
                }

                i--;
                j++;
            }
        }
    }

    printf("%d ", ans);
    return 0;
}

void zrob(int i, int j)
{
    obsikane[i][j] = 1;
    if (obraz[i - 1][j] == 1 && obsikane[i - 1][j] == 0)
    {
        zrob(i - 1, j);
    }
    if (obraz[i][j - 1] == 1 && obsikane[i][j - 1] == 0)
    {
        zrob(i, j - 1);
    }
    if (obraz[i + 1][j] == 1 && obsikane[i + 1][j] == 0)
    {
        zrob(i + 1, j);
    }
    if (obraz[i][j + 1] == 1 && obsikane[i][j + 1] == 0)
    {
        zrob(i, j + 1);
    }
    return;
}

int main()
{

    int pix;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &pix);
            obraz[i][j] = pix;
        }
    }
    row();
    snake();
    diagonal();

    int pola = 0;

    if (N % 3 == 0 && N > 3)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (obraz[i][j] == 1 && obsikane[i][j] == 0)
                {
                    pola++;
                    zrob(i, j);
                }
            }
        }
        printf("%d\n", pola);
    }

    return 0;
}
