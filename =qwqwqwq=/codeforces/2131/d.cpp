#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n; 
    std::cin >> n;
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> deg(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v; 
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if (n <= 2) {
        std::cout << 0 << "\n";
        return;
    }

    std::vector<bool> st(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            st[i] = true;
            ans++;
        }
    }

    int res = 0;
    for (int u = 1; u <= n; u++) {
        int cnt = 0;
        for (int v : adj[u]) {
            cnt += st[v];
        }
        res = std::max(res, cnt);
    }

    std::cout << (ans - res) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T; 
    std::cin >> T;

    while (T--) {
        solve();    
    }

    return 0;
}
