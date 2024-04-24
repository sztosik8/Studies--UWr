#include <iostream>
#include <vector>

using namespace std;

string has_love_triangle(int n, const vector<int>& preferences) {
    for (int i = 0; i < n; ++i) {
        int a = i + 1;
        int b = preferences[i];
        int c = preferences[b - 1];

        if (preferences[c - 1] == a) {
            return "YES";
        }
    }

    return "NO";
}

int main() {
    // Input reading
    int n;
    cin >> n;

    vector<int> preferences(n);
    for (int i = 0; i < n; ++i) {
        cin >> preferences[i];
    }

    // Output result
    string result = has_love_triangle(n, preferences);
    cout << result << endl;

    return 0;
}
