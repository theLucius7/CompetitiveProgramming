#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> g[i][j];
        }
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    int max = 0;
    
    for (int y = 0; y < m; y++) {
        dp[0][y] = g[0][y];
    }
    for (int x = 0; x < n; x++) {
        dp[x][0] = g[x][0];
    }

    for (int x = 1; x < n; x++) {
        for (int y = 1; y < m; y++) {
            if (g[x][y] == 1) {
                dp[x][y] = std::min({dp[x - 1][y], dp[x][y - 1], dp[x - 1][y - 1]}) + 1;
                max = std::max(max, dp[x][y]);
            }
        }
    }
    std::cout << max << "\n";


	return 0;
}