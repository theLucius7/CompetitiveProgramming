#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    
    SCC() {}
    SCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

void solve() {
    int n, m, h;
    std::cin >> n >> m >> h;

    std::vector<int> u(n);
    for (int i = 0; i < n; i++) {
        std::cin >> u[i];
    }

    SCC g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        
        if ((u[x] + 1) % h == u[y]) {
            g.addEdge(x, y);
        }
        if ((u[y] + 1) % h == u[x]) {
            g.addEdge(y, x);
        }
    }

    auto bel = g.work();
    std::vector<int> out(n);
    std::vector<std::vector<int>> np(g.cnt);
    for (int i = 0; i < n; i++) {
        np[bel[i]].push_back(i);
        for (auto j : g.adj[i]) {
            if (bel[i] != bel[j]) {
                out[bel[i]]++;
            }
        }
    }

    std::vector<int> ans(n);
    std::iota(ans.begin(), ans.end(), 0);
    for (int i = 0; i < g.cnt; i++) {
        if (out[i] == 0 && np[i].size() < ans.size()) {
            ans = np[i];
        }
    }

    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
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
