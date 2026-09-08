#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using i64 = long long;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> t(n), l(n), w(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> t[i] >> l[i] >> w[i];
    }

    auto check = [&](int x) -> bool {
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res += x / (t[i] * l[i] + w[i]) * l[i];
            res += min(l[i], x % (t[i] * l[i] + w[i]) / t[i]);
            if (res >= k) {
                return true;
            }
        }
        return false;
    };

    int L = 1, r = 2e18;
    while (L < r) {
        int mid = L + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << L << endl;
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