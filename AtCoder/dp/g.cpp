#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
    }

    std::vector<int> dp(N, -1);
    int ans = 0;
    auto dfs = [&](auto self, int x) -> void {
        dp[x] = 0;
        for (auto y : adj[x]) {
            if (dp[y] == -1) {
                self(self, y);
            }
            dp[x] = std::max(dp[x], dp[y] + 1);
        }
        ans = std::max(ans, dp[x]);
    };

    for (int i = 0; i < N; i++) {
        if (dp[i] == -1) {
            dfs(dfs, i);
        }
    }

    std::cout << ans << "\n";
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
