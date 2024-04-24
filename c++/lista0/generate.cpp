#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

float generateRandom(float min, float max)
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

int main()
{
    ofstream outputFile("dane.txt");

    if (!outputFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int numExamples = 100;

    for (int i = 0; i < numExamples; ++i)
    {

        float a = generateRandom(-20.0f, 100.0f);
        float b = generateRandom(-20.0f, 100.0f);
        float c = generateRandom(-20.0f, 100.0f);

        outputFile << fixed << setprecision(2) << a << " " << b << " " << c << '\n';
    }

    outputFile.close();

    cout << "Examples saved to dane.txt" << '\n';

    return 0;
}
