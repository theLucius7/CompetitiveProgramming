#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<int> ok(n, true);
    for (int i = 0; i < x; i++) {
        int a;
        std::cin >> a;
        a--;
        ok[a] = false;
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> ans;
    std::vector<bool> vis(n);

    std::queue<int> q;
    q.push(0);
    vis[0] = true;
    ans.push_back(0);
    while (q.size()) {
        int t = q.front();
        q.pop();

        for (auto v : adj[t]) {
            if (!vis[v] && ok[v]) {
                q.push(v);
                vis[v] = true;
                ans.push_back(v);
            }
        }
    }

    std::sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }

    return 0;
}