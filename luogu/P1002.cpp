#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::pair<int, int> B;
	std::cin >> n >> m >> B.first >> B.second;

	int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	std::vector<std::vector<bool>> vis(n + 1, std::vector<bool>(m + 1));
	vis[B.first][B.second] = true;
	for (int i = 0; i < 8; i++) {
		int nx = B.first + dx[i], ny = B.second + dy[i];
		if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
			vis[nx][ny] = true;
		}
	}

	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(m + 1));
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 && j == 0) {
				continue;
			}

			if (vis[i][j]) {
				continue;
			}

			if (i == 0) {
				dp[i][j] = dp[i][j - 1];
			} else if (j == 0) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
	}
	std::cout << dp[n][m] << "\n";

	return 0;
}