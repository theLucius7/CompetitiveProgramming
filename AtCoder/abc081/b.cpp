#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }

    int res = INF;
    for (int i = 0; i < n; i ++ ) {
        res = min (res, __builtin_ctz (a[i]));
    }

    cout << res << "\n";

    return 0;
}