#include <iostream>
#include <cmath>
using namespace std;

int graph[100003][100003];

int main()
{

    int n;
    cin >> n;
    int x;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            graph[i][j] = x;
        }
    }

    
}