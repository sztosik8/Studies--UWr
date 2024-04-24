/*
Katarzyna Trzos
340066
KPO
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int a, b;
    cin >> a >> b;
    int start = ceil((float)a / 2024);
    int end = floor((float)b / 2024);

    while (start <= end)
    {
        cout << start * 2024 << ' ';
        start++;
    }
}