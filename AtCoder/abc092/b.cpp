#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    vector <int> a(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }

    int res = x;

    for (int i = 0; i < n; i ++ ) {
        res += ((m - 1) / a[i]) + 1;
    }

    cout << res << "\n";

    return 0;
}