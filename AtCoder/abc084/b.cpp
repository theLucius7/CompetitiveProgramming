#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >>b;

    string s;
    cin >> s;

    for (int i = 0; i < s.size (); i ++ ) {
        if (i == a) {
            if (s[i] != '-') {
                cout << "No" << "\n";
                return 0;
            }
        } else {
            if (s[i] == '-') {
                cout << "No" << "\n";
                return 0;
            }
        }
    }

    cout << "Yes" << "\n";

    return 0;
}