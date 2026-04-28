#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
    std::cin >> n;

    std::vector<i64> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    i64 sum = std::accumulate(h.begin(), h.end(), 0LL);
    sum -= (n - 1);
    std::vector<i64> v(n);
    for (int i = 1; i < n; i++) {
        v[i] = std::max(0ll, std::min((i64)i, h[i]) - 2);
    }

    std::vector<i64> dp(n);
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1];
        if (i >= 2) {
        	dp[i] = std::max(dp[i], dp[i - 2] + v[i]);
        } else {
        	dp[i] = std::max(dp[i], v[i]);
        }
    }

    std::cout << (sum - dp[n - 1]) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
