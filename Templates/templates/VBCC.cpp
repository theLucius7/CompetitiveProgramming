struct VBCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low;
    std::vector<std::vector<int>> comps; // 存储所有点双连通分量
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
            if (y == x) { // 优化 1：直接忽略自环，防止自环干扰 low 值
                continue;
            }
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
                    comp.push_back(x); // 割点 x 属于多个点双，放入但不弹出
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
                // 优化 2：检查是否有除自环以外的有效邻接边
                bool has_edges = false;
                for (auto y : adj[i]) {
                    if (y != i) {
                        has_edges = true;
                        break;
                    }
                }
                
                if (!has_edges) {
                    comps.push_back({i}); // 真正无有效边的孤立点（或仅有自环的点）自成点双
                } else {
                    dfs(i, -1);
                    stk.pop_back(); // 优化 3：一棵 DFS 树结束后，强行弹出残留在栈底的树根，保持栈纯净
                }
            }
        }
        cnt = comps.size();
        return comps;
    }

    // ===================================================================
    // 圆方树（Block-Cut Tree）结构打包
    // ===================================================================
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
            for (auto u : comps[i]) {
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