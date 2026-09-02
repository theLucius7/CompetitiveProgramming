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
    int N, M, X;
    std::cin >> N >> M >> X;

    SCC g(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g.addEdge(x, y);
    }

    auto bel = g.work();
    std::vector<std::vector<int>> adj(g.cnt);
    std::vector<int> sz(N);
    for (int x = 0; x < N; x++) {
        sz[bel[x]]++;
        for (auto y : g.adj[x]) {
            if (bel[x] != bel[y]) {
                adj[bel[y]].push_back(bel[x]);
            }
        }
    }

    for (int i = 0; i < g.cnt; i++) {
        std::sort(adj[i].begin(), adj[i].end());
        adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    std::vector<int> dp(g.cnt), ways(g.cnt);
    for (int i = 0; i < g.cnt; i++) {
        dp[i] = sz[i];
        ways[i] = 1;
    }
    for (int x = 0; x < g.cnt; x++) {
        for (auto y : adj[x]) {
            if (dp[x] + sz[y] > dp[y]) {
                dp[y] = dp[x] + sz[y];
                ways[y] = ways[x];
            } else if (dp[y] == dp[x] + sz[y]) {
                ways[y] += ways[x];
                ways[y] %= X;
            }
        }
    }

    int mx = *max_element(dp.begin(), dp.end());
    int sum = std::transform_reduce(dp.begin(), dp.end(), ways.begin(), 0, std::plus<>(), [&](int d, int w) {return d == mx ? w : 0;}) % X;
    std::cout << mx << "\n" << sum << "\n";
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
