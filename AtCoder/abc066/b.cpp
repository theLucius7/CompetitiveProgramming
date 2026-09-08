#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (int i = s.size () - 2; i >= 0; i -= 2) {
        if (s.substr (0, i / 2) == s.substr (i / 2, i / 2)) {
            cout << i << "\n";
            return 0;
        }
    }


    return 0;
}