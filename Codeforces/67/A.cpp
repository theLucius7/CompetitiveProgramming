#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> dp(n, 1);
    for (int _ = 0; _ < n; _++) {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '=' && dp[i + 1] != dp[i]) {
                dp[i + 1] = dp[i] = std::max(dp[i + 1], dp[i]);
            } else if (s[i] == 'L' && dp[i] <= dp[i + 1]) {
                dp[i] = dp[i + 1] + 1;
            } else if (s[i] == 'R' && dp[i] >= dp[i + 1]) {
                dp[i + 1] = dp[i] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << dp[i] << " \n"[i == n - 1];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
