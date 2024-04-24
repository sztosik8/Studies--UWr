#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
 
        if (c % 2 == 0) {
            if (a > b) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        } else {
            if (b > a) {
                cout << "Second" << endl;
            } else {
                cout << "First" << endl;
            }
        }
    }
 
    return 0;
}