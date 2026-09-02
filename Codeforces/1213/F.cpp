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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> q[i];
        q[i]--;
    }

    SCC g(n);
    for (int i = 0; i + 1 < n; i++) {
        g.addEdge(p[i], p[i + 1]);
        g.addEdge(q[i], q[i + 1]);
    }

    auto bel = g.work();

    if (g.cnt < k) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    std::vector<std::vector<int>> vec(g.cnt);
    for (int i = 0; i < n; i++) {
        vec[bel[i]].push_back(i);
    }

    std::vector<char> ans(n);
    for (int i = 0; i < g.cnt; i++) {
        auto &v = vec[i];
        for (auto x : v) {
            if (i < 26) {
                ans[x] = 'z' - i;
            } else {
                ans[x] = 'a';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i];
    }
    std::cout << "\n";
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
