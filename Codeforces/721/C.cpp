#include <bits/stdc++.h>

// #define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, T;
    std::cin >> n >> m >> T;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector<int> in(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        adj[x].push_back({y, w});
        in[y]++;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    constexpr int inf = 1E9 + 10;
    std::vector dp(n, std::vector<int>(n + 1, inf)), from(n, std::vector<int>(n + 1));
    dp[0][1] = 0;
    while (q.size()) {
        auto x = q.front();
        q.pop();
        for (auto [y, w] : adj[x]) {
            for (int i = 1; i < n; i++) {
                if (dp[x][i] != inf) {
                    if (dp[x][i] + w < dp[y][i + 1]) {
                        dp[y][i + 1] = dp[x][i] + w;
                        from[y][i + 1] = x;
                    }
                }
            }
            if (--in[y] == 0) {
                q.push(y);
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[n - 1][i] <= T) {
            mx = i;
        }
    }
    std::cout << mx << "\n";

    std::vector<int> ans;
    int u = n - 1;
    while (u != 0) {
        ans.push_back(u);
        u = from[u][mx--];
    }
    ans.push_back(0);

    for (int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i] + 1 << " \n"[i == 0];
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
