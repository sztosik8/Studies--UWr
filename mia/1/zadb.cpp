#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minCostToOnes(int n, int x, int y, string& a) {
    int cost = 0;
    char prev = '1'; // Initialize prev as '1' to avoid flipping the first character if it's already '1'

    for (char c : a) {
        if (c == '0' && prev == '1') {
            cost++; // Invert substring [i...i]
        }
        prev = c;
    }

    // If the string ends with '0', it will not be counted in the loop above, so we need to add it manually
    if (a.back() == '0') {
        cost++;
    }

    // If it's cheaper to reverse the entire string, calculate the cost accordingly
    if (x < y) {
        cost = min(cost, x);
    } else {
        cost = (cost * y); // If it's cheaper to flip individual zeros
    }

    return cost;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    string a;
    cin >> a;

    // Calculate and print the minimum total cost of operations
    cout << minCostToOnes(n, x, y, a) << endl;

    return 0;
}
