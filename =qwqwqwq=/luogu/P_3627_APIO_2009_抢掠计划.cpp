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
    int N, M;
    std::cin >> N >> M;

    SCC g(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g.addEdge(x, y);
    }

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    auto bel = g.work();
    std::vector<std::vector<int>> adj(g.cnt);
    std::vector<int> w(g.cnt);
    for (int i = 0; i < N; i++) {
        w[bel[i]] += a[i];
        for (auto j : g.adj[i]) {
            if (bel[i] != bel[j]) {
                adj[bel[i]].push_back(bel[j]);
            }
        }
    }

    int S, P;
    std::cin >> S >> P;
    S--;

    std::vector<int> dp(g.cnt, -1);
    dp[bel[S]] = w[bel[S]];
    for (int x = g.cnt - 1; x >= 0; x--) {
        if (dp[x] == -1) {
            continue;
        }
        for (auto y : adj[x]) {
            dp[y] = std::max(dp[y], dp[x] + w[y]);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < P; i++) {
        int u;
        std::cin >> u;
        u--;
        ans = std::max(ans, dp[bel[u]]);
    }
    std::cout << ans << "\n";
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
