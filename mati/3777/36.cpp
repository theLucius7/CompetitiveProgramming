#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int P = 998244353;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector dp(n,std::vector<int>(n + 5));
    auto dfs = [&](auto self, int x, int p) -> void {
        int l = 1, r = 1;
        int cnt = 0;
        for (auto y : adj[x]) {
            if (y != p) {
                self(self, y, x);
                cnt++;
            }
        }

        for (int i = 0; i <= n; i++) {
            int l = 1, r = 1;
            if (i == 0) {
                r = 0;
            }
            for (auto y : adj[x]) {
                if (y != p) {
                    l *= dp[y][i + 2];
                    l %= P;
                    r *= dp[y][i];
                    r %= P;
                }
            }

            if (cnt == 0) {
                if (i == 1) {
                    dp[x][i + 1] = 1;
                } else {
                    dp[x][i + 1] = 0;
                }
            } else {
                dp[x][i + 1] = l + r;
                dp[x][i + 1] %= P;
            }
        }
    };
    dfs(dfs, 0, -1);

    std::cout << dp[0][1] << "\n";

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


	return 0;
}