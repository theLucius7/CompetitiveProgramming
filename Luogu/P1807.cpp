#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        adj[x].push_back({y, w});
    }

    constexpr int inf = 1E18;
    std::vector<int> dp(n, -inf);

    dp[0] = 0;
    for (int x = 0; x < n; x++) {
        for (auto [y, w] : adj[x]) {
            dp[y] = std::max(dp[y], dp[x] + w);
        }
    }

    std::cout << (dp[n - 1] == -inf ? -1 : dp[n - 1]) << "\n";
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
