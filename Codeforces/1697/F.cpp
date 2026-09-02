#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void addClause(int u, bool f, int v, bool g) {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};


void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    TwoSat ts(n * (k + 1));
    auto id = [&](int x, int w) {
        return w * n + x;
    };
    for (int x = 0; x < n; x++) {
        ts.addClause(id(x, 0), true, id(x, 0), true);
        ts.addClause(id(x, k), false, id(x, k), false);
        for (int w = 1; w <= k; w++) {
            if (x + 1 < n) {
                ts.addClause(id(x, w), false, id(x + 1, w), true);
            }
            ts.addClause(id(x, w), false, id(x, w - 1), true);
        }
    }

    for (int _ = 0; _ < m; _++) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int i, x;
            std::cin >> i >> x;
            i--, x--;
            ts.addClause(id(i, x), false, id(i, x + 1), true);
        } else if (op == 2) {
            int i, j, x;
            std::cin >> i >> j >> x;
            i--, j--, x -= 2;
            if (x < k) {
                ts.addClause(id(i, x + 1), false, id(i, x + 1), false);
                ts.addClause(id(j, x + 1), false, id(j, x + 1), false);
            }
            for (int w = 0; w <= std::min(x, k - 1); w++) {
                if (x + 1 - w <= k) {
                    ts.addClause(id(i, w), false, id(j, x + 1 - w), false);
                    ts.addClause(id(j, w), false, id(i, x + 1 - w), false);
                }
            }
        } else {
            int i, j, x;
            std::cin >> i >> j >> x;
            i--, j--, x -= 2;
            for (int w = 0; w <= std::min(x, k - 1); w++) {
                if (x + 1 - w <= k) {
                    ts.addClause(id(i, w), true, id(j, x + 1 - w), true);
                    ts.addClause(id(j, w), true, id(i, x + 1 - w), true);
                }
            }
        }
    }

    if (!ts.satisfiable()) {
        std::cout << "-1\n";
        return;
    }
    auto ans = ts.answer();
    for (int i = 0; i < n; i++) {
        int x;
        for (int j = 0; j < k; j++) {
            if (ans[id(i, j)]) {
                x = j;
            }
        }
        std::cout << x + 1 << " \n"[i == n - 1];
    }

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
