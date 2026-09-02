#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, b;
        std::cin >> x >> y >> b;
        x--, y--;
        if (b == 1) {
            adj[x].push_back({y, 1});
            adj[y].push_back({x, -1});
        } else {
            adj[x].push_back({y, 1});
            adj[y].push_back({x, 1});
        }
    }

    std::queue<int> q;
    std::vector<int> d(n);
    q.push(0);
    d[0] = 1;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto [y, w] : adj[x]) {
            if (d[y] == 0) {
                d[y] = d[x] + 1;
                q.push(y);
            } else {
                if ((d[x] + 1 - d[y]) % 2 == 1) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
    }

    std::vector dist(n, std::vector<int>(n, 1E9));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int x = 0; x < n; x++) {
        for (auto [y, w] : adj[x]) {
            dist[x][y] = std::min(dist[x][y], w);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";

    int mx = -1E9, S = -1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (dist[x][y] > mx) {
                mx = dist[x][y];
                S = x;
            }
        }
    }

    std::cout << mx << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << dist[S][i] << " \n"[i == n - 1];
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
