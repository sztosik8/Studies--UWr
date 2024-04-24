#include <iostream>
using namespace std;

const int MAX_COLORS = 1003; 
long long nCr[MAX_COLORS][MAX_COLORS]; 
const long long MOD = 1000000007;

void pre_compute() {
    nCr[0][0] = 1; 

    for (int i = 1; i < MAX_COLORS; i++) {
        nCr[i][0] = 1; 
        for (int j = 1; j <= i; j++) {
            nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD; 
        }
    }
}

int main() {
    pre_compute(); 

    int k;
    cin >> k;

    int* color = new int[k];
    for (int i = 0; i < k; i++)
        cin >> color[i];

    long long result = 1; 
    long long total_balls = 0; 

   
    for (int i = 0; i < k; i++) {
        total_balls += color[i]; 
        result *= nCr[total_balls - 1][color[i] - 1]; 
        result %= MOD; 
    }

    cout << result << endl;

    delete[] color; 
    return 0;
}
