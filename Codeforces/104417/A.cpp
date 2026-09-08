#include <bits/stdc++.h>
#define int long long
using i64 = long long;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    int t = 0, sum = 0;
    for (int i = 0; i < n; i ++ ) {
        sum += (a[i][0] - t) * k;
        t = a[i][0];
        sum -= a[i][1];
        if (sum < 0) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}