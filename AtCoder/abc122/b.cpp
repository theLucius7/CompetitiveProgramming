#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int res = 0;
    int cnt = 0;
    for (int i = 0; i < s.size (); i ++ ) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            cnt ++ ;
            res = max (res, cnt);
        } else {
            cnt = 0;
        }
    }

    cout << res << "\n";


    return 0;
}