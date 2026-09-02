#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

std::vector<int> w;
// std::set<std::pair<int, int>> E;
struct EBCC {
    int n;
    std::vector<std::vector<int>> adj;
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
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
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
        std::vector<int> w;
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        g.w.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            g.w[bel[i]] += w[i];
            for (auto j : adj[i]) {
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

    w.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    EBCC g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g.addEdge(u, v);
    }
    g.work();
    auto t = g.compress();
    std::vector<std::vector<int>> adj(t.n);
    for (auto [x, y] : t.edges) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<std::array<int, 2>> dp(t.n, {-1, -1});
    // [sizaizhetiaolu, zouhuilai]
    auto dfs = [&](this auto &&self, int x) -> bool {
        dp[x] = {0, 0};

        int sum = t.w[x];
        bool ok = t.siz[x] > 1;
        int mx = 0;
        for (auto y : adj[x]) {
            if (dp[y][0] == -1) {
                if (adj[y].size() > 1 || t.siz[y] > 1) {
                    ok = true;
                    sum += dp[y][1];
                    mx = std::max(mx, dp[y][0] - dp[y][1]);
                } else {
                    mx = std::max(mx, dp[y][0]);
                }
            }
        }

        dp[x] = {sum + mx, ok ? sum : 0};
        return ok;
    };

    int s;
    std::cin >> s;
    s--;
    dfs(g.bel[s]);

    std::cout << dp[g.bel[s]][0] << "\n";

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
