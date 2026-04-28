#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    a--, b--;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int s) {
        std::vector<int> dis(n, -1);
        dis[s] = 0;
        std::queue<int> q;
        q.push(s);

        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            for (auto y : adj[x]) {
                if (dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
        return dis;
    };

    auto dis = bfs(b);

    int u = -1;
    std::vector<int> vis(n);
    std::vector<int> par(n), dep(n);
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = true;

        for (auto y : adj[x]) {
            if (!vis[y]) {
                par[y] = x;
                dep[y] = dep[x] + 1;
                self(self, y);
            } else if (dep[y] < dep[x] - 1) {
                for (int i = x; ; i = par[i]) {
                    if (u == -1 || dis[i] < dis[u]) {
                        u = i;
                    }
                    
                    if (i == y) {
                        break;
                    }
                }
            }
        }
    };
    dfs(dfs, 0);

    if (bfs(u)[a] > dis[u]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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