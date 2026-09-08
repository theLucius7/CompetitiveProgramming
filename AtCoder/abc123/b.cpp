#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector <int> a(5);
    for (int i = 0; i < 5; i ++ ) {
        cin >> a[i];
    }

    int minv = INF;
    for (int i = 0; i < 5; i ++ ) {
        if (a[i] % 10 != 0) {
            minv = min (minv, a[i] % 10);
        }
    }

    int res = 0;
    if (minv != INF) {
        res = minv - 10;
    }

    for (int i = 0; i < 5; i ++ ) {
        res += (a[i] + 9) / 10 * 10;
    }

    cout << res << "\n";

    return 0;
}