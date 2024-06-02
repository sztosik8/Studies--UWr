#ifndef WYJSCIE_H
#define WYJSCIE_H

#include <fstream>
#include <string>
using namespace std;

class wyjscie
{
private:
    ofstream file;
    int key;
    string encrypt(const string &text, int key);

public:
    wyjscie(const string &filename);
    ~wyjscie();
    void set_key(int key);
    void pisz(const string &text);
};

#endif
