#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

// std::set<std::pair<int, int>> E;
struct EBCC {
    int n;
    std::vector<std::vector<std::tuple<int, int, int>>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    int tot;
    
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
        tot = 0;
    }
    
    void addEdge(int u, int v, int id) {
        adj[u].push_back({v, tot, id});
        adj[v].push_back({u, tot ^ 1, id});
        tot += 2;
    }
    
    void dfs(int x, int xid) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto [y, yid, _] : adj[x]) {
            if (yid == (xid ^ 1)) { 
                continue;
            }
            if (dfn[y] == -1) {
                // E.emplace(x, y);
                dfs(y, yid);
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
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i, -1); 
            }
        }
        return bel;
    }
    
    struct Graph {
        int n;
        std::vector<std::pair<int, int>> edges;
        std::vector<int> siz;
        std::vector<int> cnte;
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto [j, id, _] : adj[i]) {
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

    int S, T;
    std::cin >> S >> T;
    S--, T--;

    std::vector<std::vector<std::array<int, 3>>> adj(n);
    std::vector<std::array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        adj[x].push_back({y, w, i});
        adj[y].push_back({x, w, i});
        e[i] = {x, y, w};
    }

    std::vector<int> path;
    std::vector<int> stk;
    std::vector<int> vis(n);
    auto dfs = [&](this auto &&self, int x) -> void {
        vis[x] = true;

        if (x == T) {
            path = stk;
            return;
        }

        for (auto [y, w, i] : adj[x]) {
            if (!vis[y]) {
                stk.push_back(i);
                self(y);
                stk.pop_back();
            }
        }
    };

    dfs(S);

    if (!vis[T]) {
        std::cout << "0\n0\n";
        return;
    }

    int mx = 1E18;
    std::vector<int> ans;

    for (auto id : path) {
        int res = e[id][2];

        EBCC g(n);
        for (int i = 0; i < m; i++) {
            if (i == id) {
                continue;
            }
            g.addEdge(e[i][0], e[i][1], i);
        }

        auto bel = g.work();
        if (bel[S] == bel[T]) {
            continue;
        }


        std::vector<std::vector<std::tuple<int, int, int>>> nadj(g.cnt);
        for (int x = 0; x < n; x++) {
            for (auto [y, w, id] : g.adj[x]) {
                if (bel[x] != bel[y]) {
                    nadj[bel[x]].push_back({bel[y], e[id][2], id});
                }
            }
        }

        std::queue<int> q;
        std::vector<std::pair<int, int>> d(g.cnt, {-1, -1});
        q.push(bel[S]);
        d[bel[S]] = {1E18, -1};
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto [y, w, id] : nadj[x]) {
                if (d[y] == std::pair{-1, -1}) {
                    d[y] = d[x];
                    if (w < d[x].first) {
                        d[y] = {w, id};
                    }
                    q.push(y);
                }
            }
        }

        if (d[bel[T]] == std::pair{-1, -1}) {
            if (res < mx) {
                mx = res;
                ans.clear();
                ans.push_back(id);
            }
        } else {
            if (res + d[bel[T]].first < mx) {
                mx = res + d[bel[T]].first;
                ans.clear();
                ans.push_back(id);
                ans.push_back(d[bel[T]].second);
            }
        }
    }

    if (mx == 1E18) {
        std::cout << -1 << "\n";
        return;
    }
    std::cout << mx << "\n";
    std::cout << ans.size() << "\n";
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
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
