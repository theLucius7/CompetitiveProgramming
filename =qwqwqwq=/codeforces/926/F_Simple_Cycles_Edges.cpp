#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct VBCC {
    int n;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<int> vstk, estk;
    std::vector<int> dfn, low;
    std::vector<std::vector<int>> vcomps, ecomps; // 存储所有点双连通分量
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
        vstk.clear();
        estk.clear();
        vcomps.clear();
        ecomps.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v, int id) {
        adj[u].push_back({v, id});
        adj[v].push_back({u, id});
    }

    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        vstk.push_back(x);
        
        for (auto [y, id] : adj[x]) {
            if (y == x) { // 优化 1：直接忽略自环，防止自环干扰 low 值
                continue;
            }
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
                estk.push_back(id);
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
                if (low[y] >= dfn[x]) {
                    std::vector<int> vcomp, ecomp;
                    int v;
                    do {
                        v = vstk.back();
                        vstk.pop_back();
                        vcomp.push_back(v);
                    } while (v != y);

                    int e;
                    do {
                        e = estk.back();
                        estk.pop_back();
                        ecomp.push_back(e);
                    } while (e != id);


                    vcomp.push_back(x); // 割点 x 属于多个点双，放入但不弹出
                    vcomps.push_back(vcomp);
                    ecomps.push_back(ecomp);
                }
            } else if (dfn[y] < dfn[x]) {
                low[x] = std::min(low[x], dfn[y]);
                estk.push_back(id);
            }
        }
    }

    std::vector<std::vector<int>> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                // 优化 2：检查是否有除自环以外的有效邻接边
                bool has_edges = false;
                for (auto [y, id] : adj[i]) {
                    if (y != i) {
                        has_edges = true;
                        break;
                    }
                }
                
                if (!has_edges) {
                    vcomps.push_back({i}); // 真正无有效边的孤立点（或仅有自环的点）自成点双
                    ecomps.push_back({});
                } else {
                    dfs(i, -1);
                    vstk.pop_back(); // 优化 3：一棵 DFS 树结束后，强行弹出残留在栈底的树根，保持栈纯净
                }
            }
        }
        cnt = vcomps.size();
        return vcomps;
    }

    struct Tree {
        int n; // 圆方树的总节点数 = n (圆点) + cnt (方点)
        std::vector<std::pair<int, int>> edges; // 圆方树的所有双向边 (圆点 <-> 方点)
        std::vector<bool> cut; // 标记原图节点中哪些是割点
    };

    Tree compress() {
        Tree t;
        t.n = n + cnt;
        t.cut.assign(n, false);
        
        std::vector<int> deg(n, 0); // 统计每个原图节点连接的方点（点双）个数
        for (int i = 0; i < cnt; i++) {
            int square_node = n + i; // 方点索引从 n 开始
            for (auto u : vcomps[i]) {
                t.edges.emplace_back(u, square_node);
                deg[u]++;
            }
        }
        
        // 割点判定：如果一个圆点连接了超过 1 个方点（即属于多个点双），则它必定是割点
        for (int i = 0; i < n; i++) {
            if (deg[i] > 1) {
                t.cut[i] = true;
            }
        }
        return t;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    VBCC g(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g.addEdge(x, y, i);
    }

    g.work();
    auto ecomps = g.ecomps;
    auto vcomps = g.vcomps;

    std::vector<int> ans;
    for (int i = 0; i < vcomps.size(); i++) {
        if (vcomps[i].size() == ecomps[i].size()) {
            for (auto e : ecomps[i]) {
                ans.push_back(e);
            }
        }
    }

    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    std::cout << ans.size() << "\n";
    for (auto x : ans) {
        std::cout << x + 1 << " ";
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
