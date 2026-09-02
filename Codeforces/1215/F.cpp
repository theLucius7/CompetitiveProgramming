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
    int n, p, M, m;
    std::cin >> n >> p >> M >> m;

    TwoSat ts(p + M + 1);
    ts.addClause(p, true, p, true);
    ts.addClause(p + M, false, p + M, false);

    for (int i = 1; i <= M; i++) {
        ts.addClause(p + i, false, p + i - 1, true);
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        ts.addClause(x, true, y, true);
    }

    for (int i = 0; i < p; i++) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        ts.addClause(i, false, p + l, true);
        ts.addClause(i, false, p + r + 1, false);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        ts.addClause(x, false, y, false);
    }

    if (!ts.satisfiable()) {
        std::cout << -1 << "\n";
        return;
    }

    auto res = ts.answer();
    std::vector<int> ans;
    for (int i = 0; i < p; i++) {
        if (res[i]) {
            ans.push_back(i);
        }
    }

    int f;
    for (int i = 0; i < M; i++) {
        if (res[p + i]) {
            f = i;
            // break;
        }
    }

    std::cout << ans.size() << " " << f + 1 << "\n";
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
