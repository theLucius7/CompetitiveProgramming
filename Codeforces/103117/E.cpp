#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        std::sort(adj[i].begin(), adj[i].end());
    }

    int cur = 0;
    // std::vector<int> time(n);
    std::vector<int> vis(n + 5);

    int ans = -1;
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = 1;
        cur++;
        for (auto y : adj[x]) {
            if (vis[y]) {
                continue;
            }
            while (y > cur) {
                ans++;
                // std::cout << x << " " << cur << "\n";
                self(self, cur);
            } 
            
            if (y == cur) {
                self(self, y);
            }
        }
    };

    while (cur <= n - 1) {
        ans++;
        dfs(dfs, cur);
    }

    std::cout << (ans == -1 ? 0 : ans) << "\n";
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