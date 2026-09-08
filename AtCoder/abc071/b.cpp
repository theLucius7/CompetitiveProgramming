#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector <bool> st(26);
    for (int i = 0; i < s.size (); i ++ ) {
        st[s[i] - 'a'] = true;
    }

    for (int i = 0; i < 26; i ++ ) {
        if (!st[i]) {
            cout << (char) ('a' + i) << "\n";
            return 0;
        }
    }

    cout << "None" << "\n";


    return 0;
}