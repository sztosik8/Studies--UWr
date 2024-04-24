#include <iostream>
#include <cmath>

using namespace std;

double approx_pi(int x)
{
    double pi = 2.0;
    int ile = 1;
    while(ile<x)
    {
        pi = pi * sqrt( 2 / (1 + sqrt(1 - ((pi/pow(2, ile))*(pi/pow(2, ile))))));
        ile++;
    }

    return pi;
    
}


int main()
{
    cout<< approx_pi(1)<<'\n';
    
}