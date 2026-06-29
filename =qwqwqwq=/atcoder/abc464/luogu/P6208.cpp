#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int r, c;
	std::cin >> r >> c;

	std::vector g(r, std::vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> g[i][j];
		}
	}

	std::vector dp(r, std::vector<int>(c));
	dp[0][0] = g[0][0];
	for (int y = 0; y < c - 1; y++) {
		for (int x = 0; x < r; x++) {
			if (dp[x][y] == 0) {
				continue;
			}

			dp[x][y + 1] = std::max(dp[x][y + 1], dp[x][y] + g[x][y + 1]);
			if (x - 1 >= 0) {
				dp[x - 1][y + 1] = std::max(dp[x - 1][y + 1], dp[x][y] + g[x - 1][y + 1]);
			}
			if (x + 1 < r) {
				dp[x + 1][y + 1] = std::max(dp[x + 1][y + 1], dp[x][y] + g[x + 1][y + 1]);
			}
		}
	}

	std::cout << dp[r - 1][c - 1] << "\n";

	return 0;
}