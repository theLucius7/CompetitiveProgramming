#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> e(m);
    std::vector<std::vector<std::pair<int, int>>> ae(n), be(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        e[i] = {x, y};
        ae[x].push_back({y, i});
        be[y].push_back({x, i});
    }

    std::vector<bool> ais(n), bis(n);
    auto bfs = [&](int S, auto &adj, auto &vis) {
        std::queue<int> q;
        q.push(S);
        vis[S] = true;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto [y, id] : adj[x]) {
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
            }
        }
    };

    bfs(0, ae, ais);
    bfs(n - 1, be, bis);

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        auto [x, y] = e[i];
        if (ais[x] && bis[x] && ais[y] && bis[y]) {
            adj[y].push_back({x, 2});
            adj[x].push_back({y, -1});
        } else {
            ans[i] = 1;
        }
    }

    std::vector<int> d(n);
    std::queue<int> q;
    std::vector<bool> inq(n);
    std::vector<int> cnt(n);
    q.push(0);
    cnt[0]++;
    inq[0] = true;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        inq[x] = false;
        for (auto [y, w] : adj[x]) {
            if (w + d[x] < d[y]) {
                d[y] = d[x] + w;
                if (!inq[y]) {
                    if(++cnt[y] == n) {
                        std::cout << "No\n";
                        return;
                    }
                    q.push(y);
                    inq[y] = true;
                }
            }
        }
    }
    
    std::cout << "Yes\n";
    for (int i = 0; i < m; i++) {
        if (ans[i]) {
            std::cout << ans[i];
        } else {
            auto [x, y] = e[i];
            std::cout << d[x] - d[y];
        }
        std::cout << "\n";
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
