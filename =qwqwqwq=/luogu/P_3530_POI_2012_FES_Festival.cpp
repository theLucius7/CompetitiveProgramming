#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct SCC {
    int n;
    std::vector<std::vector<std::pair<int, int>>> adj;
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
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }
    
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto [y, w] : adj[x]) {
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
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;

    SCC g(n);
    for (int i = 0; i < m1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        g.addEdge(b, a, -1);
        g.addEdge(a, b, 1);
    }

    for (int i = 0; i < m2; i++) {
        int c, d;
        std::cin >> c >> d;
        c--, d--;
        g.addEdge(d, c, 0);
    }

    auto bel = g.work();
    constexpr int inf = 1E18;
    std::vector dp(n, std::vector<int>(n, inf));
    for (int x = 0; x < n; x++) {
        dp[x][x] = 0;
        for (auto [y, w] : g.adj[x]) {
            if (bel[x] == bel[y]) {
                dp[x][y] = std::min(dp[x][y], w);
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (bel[i] != bel[k]) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (bel[i] != bel[j]) {
                    continue;
                }
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    std::vector<int> cnt(g.cnt);
    for (int x = 0; x < n; x++) {
        if (dp[x][x] < 0) {
            std::cout << "NIE\n";
            return;
        }
        for (int y = 0; y < n; y++) {
            if (bel[x] == bel[y]) {
                cnt[bel[x]] = std::max(cnt[bel[x]], dp[x][y]);
            }
        }
    }

    std::cout << std::accumulate(cnt.begin(), cnt.end(), g.cnt) << "\n";
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
