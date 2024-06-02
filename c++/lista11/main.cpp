#include "wejscie.hpp"
#include "wyjscie.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "oczekiwane wywolanie: " << argv[0] << " <plik wejsciowy> <plik wyjsciowy> <klucz>" << '\n';
        return 1;
    }

    string input = argv[1];
    string output = argv[2];
    int key = atoi(argv[3]);

    try
    {
        wejscie in(input);
        wyjscie out(output);

        in.set_key(key);
        out.set_key(0);

        string line;
        line = in.czytaj();

        while (line != "")
        {
            out.pisz(line);
            line = in.czytaj();
        }
    }

    catch (const ios_base::failure &e)
    {
        cerr << "File error: " << e.what() << '\n';
        return 1;
    }
    
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
