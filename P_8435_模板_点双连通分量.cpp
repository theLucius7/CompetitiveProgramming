#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct VBCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low;
    std::vector<std::vector<int>> comps;
    int cur, cnt;

    VBCC() {}
    VBCC(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        stk.clear();
        comps.clear();
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
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
                if (low[y] >= dfn[x]) {
                    std::vector<int> comp;
                    int v;
                    do {
                        v = stk.back();
                        stk.pop_back();
                        comp.push_back(v);
                    } while (v != y);
                    comp.push_back(x);
                    comps.push_back(comp);
                }
            } else {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
    }

    std::vector<std::vector<int>> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                if (adj[i].empty()) {
                    comps.push_back({i});
                } else {
                    dfs(i, -1);
                }
            }
        }
        cnt = comps.size();
        return comps;
    }

    struct Tree {
        int n;
        std::vector<std::pair<int, int>> edges;
        std::vector<bool> cut;
    };

    Tree compress() {
        Tree t;
        t.n = n + cnt;
        t.cut.assign(n, false);
        
        std::vector<int> deg(n, 0);
        for (int i = 0; i < cnt; i++) {
            int square_node = n + i;
            for (auto u : comps[i]) {
                t.edges.emplace_back(u, square_node);
                deg[u]++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (deg[i] > 1) {
                t.cut[i] = true;
            }
        }
        return t;
    }
};



void solve() {
    
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
