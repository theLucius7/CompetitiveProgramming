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
    int n, m;
    std::cin >> n >> m;

    SCC g(n);
    std::vector<bool> u(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        if (a == b) {
            u[a] = true;
        }
        g.addEdge(a, b);
    }

    auto bel = g.work();
    // std::cout << g.cnt << "\n";
    std::vector<int> sz(g.cnt);
    std::vector<std::vector<int>> adj(g.cnt);
    for (int x = 0; x < n; x++) {
        sz[bel[x]]++;
        for (auto y : g.adj[x]) {
            if (bel[x] != bel[y]) {
                // std::cout << bel[x] << " " << bel[y] << "\n";
                adj[bel[x]].push_back(bel[y]);
            }
        }
    }

    std::vector<bool> v(g.cnt);
    for (int i = 0; i < n; i++) {
        if (u[i]) {
            v[bel[i]] = true;
        }
    }

    // for (int i = 0; i < g.cnt; i++) {
    //     std::cout << sz[i] << " \n"[i == g.cnt - 1];
    // }

    constexpr int inf = 1E10;
    std::vector<int> ways(g.cnt, 0);

    ways[bel[0]] = 1;
    for (int x = g.cnt - 1; x >= 0; x--) {
        if (ways[x] == 0) {
            continue;
        }

        if (sz[x] > 1 || v[x]) {
            ways[x] = -1;   
        }

        for (auto y : adj[x]) {
            if (ways[y] == -1) {
                continue;
            }

            if (ways[x] == -1) {
                ways[y] = -1;
            } else {
                ways[y] += ways[x];
                if (ways[y] > 2) {
                    ways[y] = 2;
                }
            }
        }
    }

    // for (int i = 0; i < g.cnt; i++) {
    //     std::cout << (ways[i] >= inf ? -1 : ways[i]) << " \n"[i == g.cnt - 1];
    // }
    // std::cout << "\n\n";

    for (int i = 0; i < n; i++) {
        if (ways[bel[i]] >= 2) {
            std::cout << 2;
        } else {
            std::cout << ways[bel[i]];
        }
        std::cout << " \n"[i == n - 1];
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
