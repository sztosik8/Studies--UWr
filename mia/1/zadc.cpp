#include <iostream>
#include <cmath>
using namespace std;


bool podzielne(string licz, int dzielnik)
{
    int n=0;
    while(licz)


}

int main()
{
    string num;
    int a, b;
    cin >> num >> a >> b;

    for (int i = 1; i < num.length(); i++)
    {
        string num1 = num.substr(0, i);
        string num2 = num.substr(i, num.length());

        if(podzielne(num1, a) && podzielne(num2, b))
        {
            cout<< num1<<" "<<num2<<'\n';
        }
    }
}
