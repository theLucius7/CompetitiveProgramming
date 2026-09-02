#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::queue<int> q;
    std::vector<bool> ok(n), o(n);
    std::vector<int> cnt(n);
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        x--;
        ok[x] = true;
        o[x] = true;
        q.push(x);
    }

    while (q.size()) {
        auto x = q.front();
        q.pop();
        for (auto y : adj[x]) {
            cnt[y]++;
            if (cnt[y] == 2 && !ok[y]) {
                ok[y] = true;
                q.push(y);
            }
        }
    }

    std::set<int> s;
    for (int x = 0; x < n; x++) {
        if (ok[x]) {
            if (!o[x]) {
                s.insert(x);
            }
            for (auto y : adj[x]) {
                if (!o[y]) {
                    s.insert(y);
                }
            }
        }
    }

    std::cout << s.size() << "\n";
    for (auto x : s) {
        std::cout << x + 1 << " ";
    }
    std::cout << "\n";
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
