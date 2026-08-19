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
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::map<int, bool> has;
    auto v = p;
    std::sort(v.begin(), v.end());
    for (auto x : v) {
        has[x] = true;
    }
    v.erase(std::unique(v.begin(), v.end()), v.end());

    auto pos = [&](int x) {
        return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
    };

    TwoSat ts(v.size());
    for (int i = 0; i < n; i++) {
        int x = a - p[i], y = b - p[i];
        if (has.contains(x)) {
            ts.addClause(pos(p[i]), false, pos(x), true);
        } else {
            ts.addClause(pos(p[i]), false, pos(p[i]), false);
        }
        if (has.contains(y)) {
            ts.addClause(pos(p[i]), true, pos(y), false);
        } else {
            ts.addClause(pos(p[i]), true, pos(p[i]), true);
        }
    }

    if (!ts.satisfiable()) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
    auto ans = ts.answer();
    for (int i = 0; i < n; i++) {
        std::cout << !ans[pos(p[i])] << " \n"[i == n - 1];
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
