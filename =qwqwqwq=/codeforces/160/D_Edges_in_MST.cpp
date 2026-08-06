#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

// std::set<std::pair<int, int>> E;
struct EBCC {
    int n;
    std::vector<std::vector<std::tuple<int, int, int>>> adj;
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
    
    void addEdge(int u, int v, int id) {
        adj[u].push_back({v, tot, id});
        adj[v].push_back({u, tot ^ 1, id});
        tot += 2;
    }
    
    void dfs(int x, int xid) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto [y, yid, id] : adj[x]) {
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
            for (auto [j, id, uid] : adj[i]) {
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

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 4>> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        edges[i] = {w, i, x, y};
    }

    std::sort(edges.begin(), edges.end());

    std::vector<std::string> ans(m);
    DSU dsu(n);
    for (int l = 0, r = 0; l < m; l = r) {
        while (r < m && edges[r][0] == edges[l][0]) {
            r++;
        }

        int cur = 0;
        std::map<int, int> p, invp;

        std::vector<std::array<int, 3>> nedges;

        for (int i = l; i < r; i++) {
            auto [w, id, x, y] = edges[i];
            int fx = dsu.find(x), fy = dsu.find(y);
            if (fx == fy) {
                ans[id] = "none";
            } else {
                ans[id] = "at least one";
                if (!p.contains(fx)) {
                    p[fx] = cur++;
                    invp[p[fx]] = fx;
                }
                if (!p.contains(fy)) {
                    p[fy] = cur++;
                    invp[p[fy]] = fy;
                }
                nedges.push_back({p[fx], p[fy], id});
            }
        }

        EBCC g(cur);
        for (auto [x, y, id] : nedges) {
            g.addEdge(x, y, id);
        }

        auto bel = g.work();
        for (int x = 0; x < cur; x++) {
            for (auto [y, _, id] : g.adj[x]) {
                if (bel[y] != bel[x]) {
                    ans[id] = "any";
                }
            }
        }

        for (int i = l; i < r; i++) {
            dsu.merge(edges[i][2], edges[i][3]);
        }
    }

    for (auto s : ans) {
        std::cout << s << "\n";
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
