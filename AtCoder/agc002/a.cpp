#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a <= 0 && b >= 0) {
        cout << "Zero" << "\n";
    } else {
        if (a < 0) {
            int c = b - a + 1;
            if (c % 2 == 0) {
                cout << "Positive" << "\n";
            } else {
                cout << "Negative" << "\n";
            }
        } else {
            cout << "Positive" << "\n";
        }
    }

    return 0;
}