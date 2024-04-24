#include <iostream>
using namespace std;

int dig[4][11];

int check(int num, int cubes)
{
    if (cubes == 1)
    {
        int je = num;
        if(dig[0][num]==1)
            return 1;
    }

    if (cubes == 2)
    {
        int je = num % 10;
        int dzie = (num / 10) % 10;

        if (dzie == 0)
        {
            if(dig[0][num]==1 or dig[1][num]==1)
                return 1;
        }

        else
        {
            if ((dig[0][je] == 1 && dig[1][dzie] == 1)
            or (dig[1][je] == 1 && dig[0][dzie] == 1))
                return 1;
        }
    }

    if (cubes == 3)
    {
        int je = num % 10;
        int dzie = (num / 10) % 10;
        int se = (num / 100) % 10;

        if (se == 0 && dzie != 0)
        {
            if((dig[0][je] == 1 && dig[1][dzie] == 1) 
            or (dig[1][je] == 1 && dig[0][dzie] == 1)
            or (dig[0][je] == 1 && dig[2][dzie] == 1) 
            or (dig[2][je] == 1 && dig[0][dzie] == 1)
            or (dig[2][je] == 1 && dig[1][dzie] == 1) 
            or (dig[1][je] == 1 && dig[2][dzie] == 1))
            return 1;
        }
        if (dzie == 0 && se == 0)
        {
            if(dig[0][je]==1 or dig[1][je]==1 or dig[2][je]==1)
                return 1;
        }

        else 
        {
            if ((dig[0][je] == 1 && dig[1][dzie] == 1 && dig[2][se] == 1) 
            or (dig[0][je] == 1 && dig[2][dzie] == 1 && dig[1][se] == 1) 
            or (dig[1][je] == 1 && dig[0][dzie] == 1 && dig[2][se] == 1) 
            or (dig[1][je] == 1 && dig[2][dzie] == 1 && dig[0][se] == 1) 
            or (dig[2][je] == 1 && dig[0][dzie] == 1 && dig[1][se] == 1)
            or (dig[2][je] == 1 && dig[1][dzie] == 1 && dig[0][se] == 1))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int cubes;
    cin >> cubes;
    for (int i = 0; i < cubes; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int num;
            cin >> num;
            dig[i][num] = 1;
        }
    }

    for (int i = 1; i < 1000; i++)
    {
        if(not (check(i, cubes)))
        {
            cout<<i-1<<'\n';
            return 0;
        }
    }
}
