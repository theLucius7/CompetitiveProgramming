#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector <int> a(s.size () + 1);
    for (int i = 0; i < s.size (); i ++ ) {
        if (s[i] == '<') {
            a[i + 1] = a[i] + 1;
        }
    }

    vector <int> b(s.size () + 1);
    for (int i = s.size () - 1; i >= 0; i -- ) {
        if (s[i] == '>') {
            b[i] = b[i + 1] + 1;
        }
    }

    LL res = 0;
    for (int i = 0; i <= s.size (); i ++ ) {
        res += max (a[i], b[i]);
    }

    cout << res << "\n";

    return 0;
}