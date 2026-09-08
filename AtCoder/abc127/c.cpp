#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int minv = 1, maxv = n;

    for (int i = 0; i < m; i ++ ) {
        int l, r;
        cin >> l >> r;
        minv = max (minv, l);
        maxv = min (maxv, r);
    }

    int res = maxv - minv + 1;
    if (res < 0) {
        res = 0;
    }

    cout << res << "\n";

    return 0;
}