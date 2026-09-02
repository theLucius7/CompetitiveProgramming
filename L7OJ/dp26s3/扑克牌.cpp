#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    std::vector<int> sum(2 * n + m);
    for (int i = 0; i < 2 * n; i++) {
        sum[i + m] = sum[i] + a[i];
    }

    int ans = -1E18;
    for (int i = 0; i <= n - 1; i++) {
        int l = i + k - 1;
        int r = (i + n - 1) / m * m + l % m;
        if (r > i + n - 1) {
            r -= m;
        }
        ans = std::max(ans, sum[r + m] - sum[l]);
    }
    std::cout << ans << "\n";
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
