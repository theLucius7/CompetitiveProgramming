#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, K;
    cin >> n >> m >> K;

    vector <int> a(n + 1), b(m + 1);
    int mina = 0x3f3f3f3f, minb = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mina = min (mina, a[i]);
    }
    for (int i = 1; i <= m; i ++ ) {
        cin >> b[i];
        minb = min (minb, b[i]);
    }


    int res = 0x3f3f3f3f;
    for (int i = 0; i < K; i ++ ) {
        int x, y, w;
        cin >> x >> y >> w;
        res = min (res, a[x] + b[y] - w);
    }

    res = min (res, mina + minb);

    cout << res << "\n";


    return 0;
}