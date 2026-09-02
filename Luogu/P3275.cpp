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
    int N, K;
    std::cin >> N >> K;

    SCC g(N + 1);

    for (int i = 0; i < K; i++) {
        int X, A, B;
        std::cin >> X >> A >> B;
        A--, B--;
        if (X == 1) {
            g.addEdge(A, B, 0);
            g.addEdge(B, A, 0);
        } else if (X == 2) {
            g.addEdge(A, B, -1);
        } else if (X == 3) {
            g.addEdge(B, A, 0);
        } else if (X == 4) {
            g.addEdge(B, A, -1);
        } else {
            g.addEdge(A, B, 0);
        }
    }
    for (int i = 0; i < N; i++) {
        g.addEdge(N, i, -1);
    }
    auto bel = g.work();

    std::vector<std::vector<std::pair<int, int>>> adj(g.cnt);
    for (int x = 0; x <= N; x++) {
        for (auto [y, w] : g.adj[x]) {
            if (bel[x] == bel[y]) {
                if (w == -1) {
                    std::cout << "-1\n";
                    return;
                }
            } else {
                adj[bel[x]].push_back({bel[y], w});
            }
        }
    }

    std::vector<int> dp(g.cnt, 1E8);
    dp[g.cnt - 1] = 0;
    for (int x = g.cnt - 1; x >= 0; x--) {
        for (auto [y, w] : adj[x]) {
            dp[y] = std::min(dp[y], dp[x] + w);
        }
    }

    for (int i = 0; i < g.cnt; i++) {
        dp[i] *= -1;
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += dp[bel[i]];
    }
    std::cout << sum << "\n";
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
