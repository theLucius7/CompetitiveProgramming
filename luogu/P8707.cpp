#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector dp(n + 1, std::vector<int>(m + 1));
	dp[1][1] = 1;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (x == 1 && y == 1) {
				continue;
			}
			if (x % 2 == 0 && y % 2 == 0) {
				continue;
			}
			dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
		}
	}

	std::cout << dp[n][m] << "\n";


	return 0;
}