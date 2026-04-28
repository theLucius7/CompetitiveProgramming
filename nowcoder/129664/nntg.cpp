#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int m = 0;
    for (int i = 0; i < n; i++) if (a[i]) m++;
    std::vector<i64> dp(m + 1, -(i64)4e18), ndp(m + 1, -(i64)4e18);
    dp[0] = 0;
    int c1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) c1++;
        std::fill(ndp.begin(), ndp.end(), -(i64)4e18);
        for (int j = 0; j <= c1; j++) {
            if (dp[j] < -(i64)2e18) continue;
            ndp[j] = std::max(ndp[j], dp[j]);
            if (j + 1 <= c1) ndp[j + 1] = std::max(ndp[j + 1], dp[j] + (i64)(i - j));
        }
        dp.swap(ndp);
    }
    i64 ans = 0;
    for (int j = 0; j <= m; j++) {
        if (dp[j] < -(i64)2e18) continue;
        ans = std::max(ans, dp[j] - (i64)k * j);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
