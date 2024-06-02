#ifndef WEJSCIE_H
#define WEJSCIE_H

#include <fstream>
#include <string>
using namespace std;

class wejscie
{
private:
    ifstream file;
    int key;
    string decrypt(const string &text, int key);

public:
    wejscie(const string &filename);
    ~wejscie();
    void set_key(int key);
    string czytaj();
};

#endif