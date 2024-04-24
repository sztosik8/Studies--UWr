#include <iostream>
#include <cmath>
using namespace std;

char carpet[23][23];

int main()
{
    int t;
    int n, m;
    cin >> t;
    int prev = 0;

    char let;
    for (int k = 0; k < t; k++)
    {

        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> let;
                carpet[i][j] = let;
            }
        }

        string vika = "vika";
        // 0  1  2  3
        // V  I  K  A
        int p = 0;


      
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (carpet[j][i] == vika[p])
                    {
                        p++;

                        break;
                    }
                }
            }
            if (p == 4)
            {
                cout << "yes" << '\n';
            }
            else
            {
                cout << "no" << '\n';
            }
        }
    
}