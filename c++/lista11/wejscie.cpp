#include "wejscie.hpp"
#include <stdexcept>

#include <iostream>
#include <cctype>
using namespace std;

wejscie::wejscie(const string &filename) 
{
    key = 0;
    file.open(filename);
    if (!file.is_open())
    {
        throw ios_base::failure("nie mozna otworzyc pliku wejsciowego");
    }
    file.exceptions(ifstream::failbit);
}

wejscie::~wejscie()
{
    if (file.is_open())
    {
        file.close();
    }
}

void wejscie::set_key(int k)
{
    key = k % 26;
    if(key<0)
    {
        key+=26;
    }
}

string wejscie::czytaj()
{
    string line;
    if (file.eof() || !(getline(file, line)))
    {
        return "";
    }
    else
    {
        return decrypt(line, key);
    }
}

string wejscie::decrypt(const string &text, int key)
{
    string result = text;
    char base;
    for (char &c : result)
    {
        if (isalpha(c))
        {
            if (islower(c))
            {
                base = 'a';
            }
            else
                base = 'A';

            c = (c - base - key + 26) % 26 + base;
        }
    }
    return result;
}
