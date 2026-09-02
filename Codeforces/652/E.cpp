#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

// std::set<std::pair<int, int>> E;
struct EBCC {
    int n;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    
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
    }
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto [y, w] : adj[x]) {
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
                // E.emplace(x, y);
                dfs(y, x);
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
        dfs(0, -1);
        return bel;
    }
    
    struct Graph {
        int n;
        std::vector<std::pair<int, int>> edges;
        std::vector<int> siz;
        std::vector<int> cnte;

        std::vector<std::vector<std::pair<int, int>>> adj;
        std::vector<int> w;
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);

        g.w.resize(cnt);
        g.adj.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto [j, w] : adj[i]) {
                if (bel[i] == bel[j]) {
                    if (w) {
                        g.w[bel[i]]++;
                    }
                } else {
                    g.adj[bel[i]].push_back({bel[j], w});
                    g.adj[bel[j]].push_back({bel[i], w});
                }

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
    int n, m;
    std::cin >> n >> m;

    EBCC t(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        t.addEdge(x, y, w);
    }

    auto bel = t.work();

    auto g = t.compress();

    

    int S, T;
    std::cin >> S >> T;
    S--, T--;

    std::vector<int> d(g.n, -1);
    std::queue<int> q;
    q.push(bel[S]);
    d[bel[S]] = g.w[bel[S]];
    while (!q.empty()) {
        auto x = q.front();
        q.pop();

        if (x == bel[T]) {
            std::cout << (d[x] ? "YES" : "NO") << "\n";
            return;
        }

        for (auto [y, w] : g.adj[x]) {
            if (d[y] == -1) {
                d[y] = d[x] + w + g.w[y];
                q.push(y);
            }
        }
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
