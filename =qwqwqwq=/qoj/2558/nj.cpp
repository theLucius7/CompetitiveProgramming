#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int inf = 1E18;

using i64 = long long;

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

void solve() {
    int n, Q;
    std::cin >> n >> Q;

    HLD hld(n);

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        hld.addEdge(x, y);
    }
    hld.work();

    auto dfs = [&](auto self, int x, int fa) -> void {
        for (int y : adj[x]) {
            if (y != fa) {
                self(self, y, x);
            }
        }

        int cnt = 0;
        int min0 = inf, min1 = inf;
        for (int y : adj[x]) {
            if (y != fa) {
                cnt++;
                if (min0 > c[y]) {
                    min1 = min0;
                    min0 = c[y];
                } else {
                    min1 = std::min(min1, c[y]);
                }
            }
        }

        if (cnt != 0) {
            c[x] = std::min(c[x], min0 + min1);
        }
    };

    dfs(dfs, 0, -1);

    std::queue<int> q;
    q.push(0);
    std::vector<bool> vis(n);    

    std::vector<std::vector<std::pair<int, int>>> bdj(n);

    while (q.size()) {
        int x = q.front();
        vis[x] = true;
        q.pop();

        int min0 = inf, min1 = inf;

        for (int y : adj[x]) {
            if (!vis[y]) {
                if (min0 > c[y]) {
                    min1 = min0;
                    min0 = c[y];
                } else {
                    min1 = std::min(min1, c[y]);
                }
            }
        }

        for (int y : adj[x]) {
            if (!vis[y]) {
                if (c[y] == min0) {
                    bdj[x].emplace_back(y, min1);
                } else {
                    bdj[x].emplace_back(y, min0);
                }
                q.push(y);
            }
        }
    }


    std::vector<i64> dis(n, inf);
    std::priority_queue<std::pair<i64,int>, std::vector<std::pair<i64,int>>, std::greater<std::pair<i64,int>>> pq;

    pq.emplace(0, 0);
    dis[0] = 0;
    while (!pq.empty()) {
        i64 d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dis[u]) {
            continue;
        }
        for (int i = 0; i < bdj[u].size(); i++) {
            int v = bdj[u][i].first;
            i64 w = bdj[u][i].second;
            if (dis[v] > d + w) {
                dis[v] = d + w;
                pq.emplace(dis[v], v);
            }
        }
    }


    while (Q--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        if (hld.lca(x, y) != y) {
            cout << "-1\n";
        } else {
            std::cout << dis[x] - dis[y] << "\n";
        }
    }
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


	return 0;
}