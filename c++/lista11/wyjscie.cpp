#include "wyjscie.hpp"
#include <stdexcept>
using namespace std;

wyjscie::wyjscie(const string &filename) 
{
    key=0;
    file.open(filename);
    if (!file.is_open())
    {
        throw ios_base::failure("nie mozna otworzyc pliku wyjsciowego");
    }
    file.exceptions(ofstream::failbit);
}

wyjscie::~wyjscie()
{
    if (file.is_open())
    {
        file.close();
    }
}

void wyjscie::set_key(int k)
{
    key = k % 26;
    if(key<0)
    {
        key+=26;
    }
}

void wyjscie::pisz(const string &text)
{
    string encrypted_text = encrypt(text, key);
    file << encrypted_text << '\n';
}

string wyjscie::encrypt(const string &text, int key)
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

            c = (c - base + key) % 26 + base;
        }
    }
    return result;
}
