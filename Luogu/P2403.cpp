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
    int N, R, C;
    std::cin >> N >> R >> C;

    std::vector<int> r(N), c(N), t(N);
    std::vector<std::pair<int, int>> a;
    std::map<std::pair<int, int>, int> ap;
    std::map<int, std::set<int>> sR, sC;
    int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
    std::set<int> vec;
    for (int _ = 0; _ < N; _++) {
        int x, y, T;
        std::cin >> x >> y >> T;
        x--, y--;
        r[_] = x, c[_] = y, t[_] = T;

        if (!ap.contains({x, y})) {
            a.push_back({x, y});
            ap[{x, y}] = a.size() - 1;
        }
        sR[x].insert(y);
        sC[y].insert(x);
        if (T == 1) {
            if (!ap.contains({x, -1})) {
                a.push_back({x, -1});
                ap[{x, -1}] = a.size() - 1;
            }
            vec.insert(ap[{x, -1}]);
        } else if (T == 2) {
            if (!ap.contains({-1, y})) {
                a.push_back({-1, y});
                ap[{-1, y}] = a.size() - 1;
            }
            vec.insert(ap[{-1, y}]);
        }
    }

    SCC g(a.size());
    for (auto v : vec) {
        if (a[v].first == -1) {
            int y = a[v].second;
            for (auto x : sC[y]) {
                g.addEdge(v, ap[{x, y}]);
            }
        } else {
            int x = a[v].first;
            for (auto y : sR[x]) {
                g.addEdge(v, ap[{x, y}]);
            }
        }
    }

    for (int _ = 0; _ < N; _++) {
        int x = r[_], y = c[_], T = t[_];
        if (T == 1) {
            g.addEdge(ap[{x, y}], ap[{x, -1}]);
        } else if (T == 2) {
            g.addEdge(ap[{x, y}], ap[{-1, y}]);
        } else {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C && ap.contains({nx, ny})) {
                    g.addEdge(ap[{x, y}], ap[{nx, ny}]);
                }
            }
        }
    }

    auto bel = g.work();
    std::vector<int> sz(g.cnt);
    std::vector<std::vector<int>> adj(g.cnt);
    for (int x = 0; x < a.size(); x++) {
        if (a[x].first != -1 && a[x].second != -1) {
            sz[bel[x]]++;
        }
        for (auto y : g.adj[x]) {
            if (bel[x] != bel[y]) {
                adj[bel[x]].push_back(bel[y]);
            }
        }
    }

    std::vector<int> dp(g.cnt);
    int ans = 0;
    for (int x = g.cnt - 1; x >= 0; x--) {
        dp[x] = std::max(dp[x], sz[x]);
        for (auto y : adj[x]) {
            dp[y] = std::max(dp[y], dp[x] + sz[y]);
        }
        ans = std::max(ans, dp[x]);
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
