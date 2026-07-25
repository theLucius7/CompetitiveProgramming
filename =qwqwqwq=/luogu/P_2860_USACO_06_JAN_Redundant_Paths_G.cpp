#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct EBCC {
    int n;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    int tot;
    
    EBCC() {}
    EBCC(int n) {
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
        tot = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back({v, tot});
        adj[v].push_back({u, tot ^ 1});
        tot += 2;
    }
    
    void dfs(int x, int xid) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto [y, yid] : adj[x]) {
            if (yid == (xid ^ 1)) {
                continue;
            }
            if (dfn[y] == -1) {
                // E.emplace(x, y);
                dfs(y, yid);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1 && dfn[y] < dfn[x]) {
                // E.emplace(x, y);
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
                dfs(i, -1); 
            }
        }
        return bel;
    }
    
    struct Graph {
        int n;
        std::vector<std::pair<int, int>> edges;
        std::vector<int> siz;
        std::vector<int> cnte;
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto [j, id] : adj[i]) {
                if (bel[i] < bel[j]) {
                    g.edges.emplace_back(bel[i], bel[j]);
                } else if (i < j) {
                    g.cnte[bel[i]]++;
                }
            }
        }
        return g;
    }
};

void solve() {
    int F, R;
    std::cin >> F >> R;

    EBCC g(F);
    for (int i = 0; i < R; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g.addEdge(u, v);
    }

    auto bel = g.work();
    auto G = g.compress();
    std::vector<int> cnt(g.cnt);
    for (auto [x, y] : G.edges) {
        cnt[x]++;
        cnt[y]++;
    }

    std::cout << (std::count(cnt.begin(), cnt.end(), 1) + 1) / 2 << "\n";
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
