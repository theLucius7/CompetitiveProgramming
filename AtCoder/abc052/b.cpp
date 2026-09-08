#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int x = 0;
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] == 'I') {
            x ++ ;
        } else if (s[i] == 'D') {
            x -- ;
        }
        res = max (res, x);
    }

    cout << res << "\n";

    return 0;
}