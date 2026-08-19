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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int l;
        std::cin >> l;
        v[i].resize(l);
        for (int j = 0; j < l; j++) {
            int s;
            std::cin >> s;
            s--;
            v[i][j] = s;
        }
    }

    TwoSat ts(m);
    for (int i = 0; i + 1 < n; i++) {
        int j = i + 1;
        for (int k = 0; k < v[i].size(); k++) {
            if (k >= v[j].size()) {
                std::cout << "No\n";
                return;
            }
            if (v[i][k] != v[j][k]) {
                if (v[i][k] < v[j][k]) {
                    ts.addClause(v[j][k], false, v[i][k], true);
                } else {
                    ts.addClause(v[i][k], true, v[i][k], true);
                    ts.addClause(v[j][k], false, v[j][k], false);
                }
                break;
            }
        }
    }

    if (!ts.satisfiable()) {
        std::cout << "No\n";
        return;
    }
    std::cout << "Yes\n";
    auto res = ts.answer();
    std::vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (res[i]) {
            ans.push_back(i);
        }
    }
    std::cout << ans.size() << "\n";
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
