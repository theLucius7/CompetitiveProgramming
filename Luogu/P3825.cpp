#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    std::vector<int> id, dfn, low;
    TwoSat(int n) : n(n), e(2 * n), ans(n), id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1) {}
    void addClause(int u, bool f, int v, bool g) {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() {
        // std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
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
            if (id[2 * i] == id[2 * i + 1]) {
                for (int _ = 0; _ < 2 * n; _++) {
                    e[_].clear();
                    id[_] = -1;
                    dfn[_] = -1;
                    low[_] = -1;
                }
                return false;
            }
            ans[i] = id[2 * i] > id[2 * i + 1];
        }

        for (int _ = 0; _ < 2 * n; _++) {
            e[_].clear();
            id[_] = -1;
            dfn[_] = -1;
            low[_] = -1;
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};


void solve() {
    int n, d;
    std::cin >> n >> d;

    std::string S;
    std::cin >> S;

    std::vector<int> ps;
    for (int i = 0; i < n; i++) {
        if (S[i] == 'x') {
            ps.push_back(i);
        }
    }

    int m;
    std::cin >> m;

    std::vector<std::tuple<int, char, int, char>> rules(m);
    for (int _ = 0; _ < m; _++) {
        int i, j;
        char hi, hj;
        std::cin >> i >> hi >> j >> hj;
        i--, j--;
        rules[_] = {i, hi, j, hj};
    }

    std::vector<std::array<int, 2>> gt(3);
    int mp[3][3];
    for (int i = 0; i < 3; i++) {
        int l = (i + 2) % 3, r = (i + 1) % 3;
        gt[i] = {l, r};
        mp[i][l] = 0;
        mp[i][r] = 1;
    }

    auto calc = [&](char mpi, char cri, char mpj, char crj) {
        std::pair<int, int> res{-1, -1};
        if (std::tolower(cri) == mpi) {
            return res;
        }
        res.first = mp[mpi - 'a'][cri - 'A'];
        if (std::tolower(crj) == mpj) {
            return res;
        }
        res.second = mp[mpj - 'a'][crj - 'A'];
        return res;
    };

    TwoSat ts(n);
    for (int _ = 0; _ < (1 << d); _++) {
        for (int i = 0; i < d; i++) {
            if (_ >> i & 1) {
                S[ps[i]] = 'a';
            } else {
                S[ps[i]] = 'b';
            }
        }
        
        for (int k = 0; k < m; k++) {
            auto [i, hi, j, hj] = rules[k];
            auto res = calc(S[i], hi, S[j], hj);
            if (res.first == -1) {
                continue;
            } else if (res.second == -1) {
                auto f = !res.first;
                ts.addClause(i, f, i, f);
            } else {
                ts.addClause(i, !res.first, j, res.second);
            }
        }

        if (ts.satisfiable()) {
            auto ans = ts.answer();
            for (int i = 0; i < n; i++) {
                std::cout << char(gt[S[i] - 'a'][ans[i]] + 'A');
            }
            std::cout << "\n";
            return;
        }
    }
    std::cout << "-1\n";
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
