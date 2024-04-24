#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> hairlines(n);
    for (int i = 0; i < n; i++)
        cin >> hairlines[i];

    int time = 0;

    for (int i = 0; i < n; i++) {
        if (hairlines[i] > l) {
            time++;
            while (i < n && hairlines[i] > l)
                i++;
        }
    }

    for (int i = 0; i < m; i++) {
        int t, p, d;
        cin >> t;

        if (t == 0)
            cout << time << '\n';
        else {
            cin >> p >> d;
            p--;

            if (hairlines[p] <= l) {
                hairlines[p] += d;
                if (hairlines[p] > l) {
                    if ((p == 0 || hairlines[p - 1] <= l) && (p == n - 1 || hairlines[p + 1] <= l))
                        time++;
                    else if ((p > 0 && hairlines[p - 1] > l) && (p < n - 1 && hairlines[p + 1] > l))
                        time--;
                }
            }
        }
    }

    return 0;
}
