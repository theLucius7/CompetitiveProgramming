#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector <bool> st(26);
    for (int i = 0; i < s.size (); i ++ ) {
        if (!st[s[i] - 'a']) {
            st[s[i] - 'a'] = true;
        } else {
            cout << "no" << "\n";
            return 0;
        }
    }

    cout << "yes" << "\n";

    return 0;
}