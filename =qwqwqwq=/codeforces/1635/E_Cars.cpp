#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> e(m);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int op, x, y;
        std::cin >> op >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        e[i] = {op, x, y};
    }

    std::vector<int> col(n, -1);
    auto dfs = [&](this auto &&self, int x, int c) -> bool {
        col[x] = c;
        for (auto y : adj[x]) {
            if (col[y] == -1) {
                if (!self(y, c ^ 1)) {
                    return false;
                }
            } else if (col[y] != c ^ 1) {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            if (!dfs(i, 0)) {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::vector<std::vector<int>> nadj(n);
    std::vector<int> in(n);
    for (int i = 0; i < m; i++) {
        auto [op, x, y] = e[i];
        if (op == 1) {
            if (col[x] == 0) {
                nadj[x].push_back(y);
                in[y]++;
            } else {
                nadj[y].push_back(x);
                in[x]++;
            }
        } else {
            if (col[x] == 0) {
                nadj[y].push_back(x);
                in[x]++;
            } else {
                nadj[x].push_back(y);
                in[y]++;
            }
        }
    }
    
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> ord;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        ord.push_back(x);
        for (auto y : nadj[x]) {
            if (--in[y] == 0) {
                q.push(y);
            }
        }
    }

    if (ord.size() < n) {
        std::cout << "NO\n";
        return;
    }

    std::vector<std::pair<char, int>> ans(n);
    for (int i = 0; i < n; i++) {
        int u = ord[i];
        if (i == 0) {
            ans[u] = {col[u] ? 'R' : 'L', 0};
        } else {
            int lu = ord[i - 1];
            ans[u] = {col[u] ? 'R' : 'L', ans[lu].second + 1};
        }
    }
    std::cout << "YES\n";
    for (auto [c, x] : ans) {
        std::cout << c << " " << x << "\n";
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
