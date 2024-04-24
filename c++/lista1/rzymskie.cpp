/*
Katarzyna Trzos
Lista 1
Kurs C++
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
const vector<pair<int, string>> roman = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}};

string toroman(int x)
{
    string ans = "";
    int i = 0;
    while (x > 0)
    {
        while (x >= roman[i].first)
        {
            ans.append(roman[i].second);

            x -= roman[i].first;
        }
        i++;
    }
    return ans;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        int x;
        try
        {
            x = stoi(argv[i], nullptr, 10);
            if (x < 1 or x >= 4000)
                throw 1;
        }
        catch (...)
        {
            clog << "Blad wejscia\n";
            continue;
        }
        cout << toroman(x) << "\n";
    }
}
