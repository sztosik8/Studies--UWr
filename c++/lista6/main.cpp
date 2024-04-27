/*
Katarzyna Trzos
Lista 5
Kurs C++
*/

#include "wielom.cpp"
#include <iostream>
using namespace std;

int main()
{
    wielom w = wielom();
    cout <<w << '\n' ;
    wielom v = wielom();
    cout <<v << '\n';
    w+=v;
   
    cout <<w << '\n' << '\n';
    w*=6;
    cout <<w << '\n' << '\n';

    try
    {
        
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }

    try
    {
        cout << w[9];
    }
    catch (invalid_argument const &ex)
    {
        cerr << ex.what() << '\n';
    }
}