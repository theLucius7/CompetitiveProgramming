#include <bits/stdc++.h>

using i64 = long long;

void solve () {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> d(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        d[u]++;
        d[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (d[i] > 2) {
            std::cout << adj[i][0] + 1 << " " << i + 1 << " " << adj[i][1] + 1 << "\n";//
            return;
        }   
    }
    std::cout << -1 << "\n";///
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}