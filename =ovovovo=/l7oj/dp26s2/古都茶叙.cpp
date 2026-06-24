#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int sum = 0;
    for (int l = 0, r = 0; l < 2 * n; l++) {
        while (r < 2 * n && sum + a[r % n] >= 0) {
            sum += a[r % n];
            r++;
        }
        if (r - l >= n) {
            std::cout << l + 1 << "\n";
            return;
        }
        if (l == r) {
            r++;
        } else {
            sum -= a[l];
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
