#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k, c;
    std::cin >> n >> k >> c;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int s) {
        std::queue<int> q;
        std::vector d(n, -1);
        d[s] = 0;
        q.push(s);
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto y : adj[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }

        return d;
    };

    auto d0 = bfs(0);
    auto s = std::distance(d0.begin(), std::max_element(d0.begin(), d0.end()));

    auto ds = bfs(s);
    auto t = std::distance(ds.begin(), std::max_element(ds.begin(), ds.end()));

    auto dt = bfs(t);

    constexpr int inf = 1E18;
    int mx = -inf;
    for (int i = 0; i < n; i++) {
        mx = std::max(mx, k * std::max(ds[i], dt[i]) - c * d0[i]);
    }
    std::cout << mx << "\n";
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
