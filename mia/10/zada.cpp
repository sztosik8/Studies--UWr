#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        if (str.length() > 1 && str[0] == str[1]) {
            cout << str[0] << str[1] << endl;
            continue;
        }

        cout << str[0];
        int i = 1;
        for (; i < n; i++) {
            if (str[i] <= str[i - 1])
                cout << str[i];
            else
                break;
        }
        for (i--; i >= 0; i--) {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}