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
    int n;
    std::cin >> n;

    SCC g(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        g.addEdge(i, x);
    }

    auto bel = g.work();

    std::vector<int> has(g.cnt);
    std::vector<int> in(g.cnt), out(g.cnt);
    for (int x = 0; x < n; x++) {
        has[bel[x]] = x;
        for (auto y : g.adj[x]) {
            if (bel[x] != bel[y]) {
                out[bel[x]]++;
                in[bel[y]]++;
            }
        }
    }

    if (g.cnt == 1) {
        std::cout << 0 << "\n";
        return;
    }

    std::vector<int> a, b;
    for (int i = 0; i < g.cnt; i++) {
        if (out[i] == 0) {
            a.push_back(i);
        } 
        if (in[i] == 0) {
            b.push_back(i);
        }
    }

    int mx = std::max(a.size(), b.size());
    std::cout << mx << "\n";
    for (int i = 0; i < mx; i++) {
        std::cout << (i < a.size() ? has[a[i]] + 1 : has[a.back()] + 1) << " " << (i < b.size() ? has[b[i]] + 1: has[b.back()] + 1) << "\n";
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
