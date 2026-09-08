#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < 8; i ++ ) {
        if (n < (1 << (i + 1))) {
            cout << (1 << i) << "\n";
            return 0;
        }
    }

    return 0;
}