#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

// std::set<std::pair<int, int>> E;
std::vector<std::pair<int, int>> ans;
struct EBCC {
    int n;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    int id;
    
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
        id = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back({v, id});
        adj[v].push_back({u, id});
        id++;
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto [y, id] : adj[x]) {
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
                // E.emplace(x, y);
                ans[id] = {x, y};
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1 && dfn[y] < dfn[x]) {
                // E.emplace(x, y);
                ans[id] = {x, y};
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
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        g.adj.resize(cnt);

        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto [j, id] : adj[i]) {
                if (bel[i] != bel[j]) {
                    g.adj[bel[i]].push_back({bel[j], id});
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

    ans.resize(m);
    EBCC t(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        t.addEdge(x, y);
    }

    auto bel = t.work();

    auto g = t.compress();
    int mx = 0, S;
    for (int i = 0; i < g.n; i++) {
        if (g.siz[i] > mx) {
            mx = g.siz[i];
            S = i;
        }
    }

    std::queue<int> q;
    std::vector<bool> vis(g.n);
    q.push(S);
    vis[S] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto [y, id] : g.adj[x]) {
            if (!vis[y]) {
                if (bel[ans[id].second] == y) {
                    std::swap(ans[id].first, ans[id].second);
                }
                vis[y] = true;
                q.push(y);
            }
        }
    }

    std::cout << mx << "\n";
    for (auto [x, y] : ans) {
        std::cout << x + 1 << " " << y + 1 << "\n";
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
