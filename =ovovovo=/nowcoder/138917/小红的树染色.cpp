#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto bfs = [&](int u) {
        std::queue<int> q;
        std::vector<int> d(n, -1);
        q.push(u);
        d[u] = 0;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto y : adj[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }
        return d;
    };

    auto d0 = bfs(0);
    int mx = -1, S = 0, T = 0;
    for (int i = 0; i < n; i++) {
        if (d0[i] > mx && s[i] == '1') {
            mx = d0[i];
            S = i;
        }
    }
    auto dS = bfs(S);
    mx = -1;
    for (int i = 0; i < n; i++) {
        if (dS[i] > mx && s[i] == '1') {
            mx = dS[i];
            T = i;
        }
    }
    auto dT = bfs(T);

    for (int i = 0; i < n; i++) {
        std::cout << std::max({dS[T], dS[i], dT[i]}) << "\n";
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
