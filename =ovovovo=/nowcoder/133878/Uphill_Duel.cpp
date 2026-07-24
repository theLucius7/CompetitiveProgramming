#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> g[i][j];
        }
    }

    std::vector<std::vector<int>> adj(n * m);
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] > g[x][y]) {
                    adj[x * m + y].push_back(nx * m + ny);
                }
            }
        }
    }

    std::vector<int> dp(n * m, -1);
    auto dfs = [&](auto self, int x) -> void {
        dp[x] = 0;
        for (auto y : adj[x]) {
            if (dp[y] == -1) {
                self(self, y);
            }
            if (dp[y] == 0) {
                dp[x] = 1;
            }
        }
    };
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (dp[x * m + y] == -1) {
                dfs(dfs, x * m + y);
            }
        }
    }

    int q;
    std::cin >> q;

    while (q--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        std::cout << (dp[x * m + y] == 0 ? "Second" : "First") << "\n";
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
