#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int res = INF;
    for (int i = 0; i + 2 < s.size (); i ++ ) {
        int x = stoi (s.substr (i, 3));
        res = min (res, abs (x - 753));
    }

    cout << res << "\n";

    return 0;
}