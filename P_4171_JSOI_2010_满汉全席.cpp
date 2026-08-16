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
    int n, m;
    std::cin >> n >> m;

    auto nt = [&](int x) {
        return x >= n ? x - n : x + n;
    };

    SCC scc(2 * n);
    while (m--) {
        std::string sa, sb;
        std::cin >> sa >> sb;

        int a = std::stoll(sa.substr(1)) - 1, b = std::stoll(sb.substr(1)) - 1;
        if (sa[0] == 'h') {
            a += n;
        }
        if (sb[0] == 'h') {
            b += n;
        }

        scc.addEdge(nt(a), b);
        scc.addEdge(nt(b), a);
    }

    auto bel = scc.work();

    for (int i = 0; i < n; i++) {
        if (bel[i] == bel[i + n]) {
            std::cout << "BAD\n";
            return;
        }
    }
    std::cout << "GOOD\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
