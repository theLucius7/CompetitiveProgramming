#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    constexpr int inf = 1E18;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    std::vector<int> dis(n, inf);    
    pq.push({1, 0});
    dis[0] = 1;

    while (!pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();

        if (d > dis[x]) {
            continue;
        }

        for (auto y : adj[x]) {
            int nd = std::max(d, y + 1);
            if (nd < dis[y]) {
                dis[y] = nd;
                pq.push({nd, y});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << (dis[i] == inf ? -1 : dis[i]) << " \n"[i == n - 1];
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
