#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H;
	std::cin >> H;

	std::vector<std::vector<int>> g(H, std::vector<int>(H));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < H; j++) {
			std::cin >> g[i][j];
		}
	}

	std::vector<std::vector<std::vector<int>>> cnt(11, std::vector<std::vector<int>>(H, std::vector<int>(H)));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < H; j++) {
			if (i == 0) {
				cnt[g[i][j]][i][j] = 1;
				continue; 
			}
			cnt[g[i][j]][i][j] = cnt[g[i][j]][i - 1][j] + 1;
		}
	}

	int max = 1;
	for (int i = 0; i < H; i++) {
		std::vector<std::vector<int>> dp(11, std::vector<int>(H));
		for (int j = 0; j < H; j++) {
			if (j == 0) {
				dp[g[i][j]][j] = 1;
				continue;
			}
			dp[g[i][j]][j] = std::min(dp[g[i][j]][j - 1] + 1, cnt[g[i][j]][i][j]);
			max = std::max(max, dp[g[i][j]][j]);
		}
	}


	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j < H; j++) {
			std::reverse(cnt[i][j].begin(), cnt[i][j].end());
		}
	}
	for (int x = 0; x < H; x++) {
		std::reverse(g[x].begin(), g[x].end());
	}


	for (int i = 0; i < H; i++) {
		std::vector<std::vector<int>> dp(11, std::vector<int>(H));
		for (int j = 0; j < H; j++) {
			if (j == 0) {
				dp[g[i][j]][j] = 1;
				continue;
			}
			dp[g[i][j]][j] = std::min(dp[g[i][j]][j - 1] + 1, cnt[g[i][j]][i][j]);
			max = std::max(max, dp[g[i][j]][j]);
		}
	}

	for (int x = 0; x < H; x++) {
		std::reverse(g[x].begin(), g[x].end());
	}

	cnt.assign(11, std::vector<std::vector<int>>(H, std::vector<int>(H, 0)));

	for (int x = H - 1; x >= 0; x--) {
		for (int y = 0; y < H; y++) {
			if (x == H - 1) {
				cnt[g[x][y]][x][y] = 1;
				continue;
			}
			cnt[g[x][y]][x][y] = cnt[g[x][y]][x + 1][y] + 1;
		}
	}

	for (int i = 0; i < H; i++) {
		std::vector<std::vector<int>> dp(11, std::vector<int>(H));
		for (int j = 0; j < H; j++) {
			if (j == 0) {
				dp[g[i][j]][j] = 1;
				continue;
			}
			dp[g[i][j]][j] = std::min(dp[g[i][j]][j - 1] + 1, cnt[g[i][j]][i][j]);
			max = std::max(max, dp[g[i][j]][j]);
		}
	}


	for (int i = 0; i <= 10; i++) {
		for (int x = 0; x < H; x++) {
			std::reverse(cnt[i][x].begin(), cnt[i][x].end());
		}
	}
	for (int x = 0; x < H; x++) {
		std::reverse(g[x].begin(), g[x].end());
	}

	for (int i = 0; i < H; i++) {
		std::vector<std::vector<int>> dp(11, std::vector<int>(H));
		for (int j = 0; j < H; j++) {
			if (j == 0) {
				dp[g[i][j]][j] = 1;
				continue;
			}
			dp[g[i][j]][j] = std::min(dp[g[i][j]][j - 1] + 1, cnt[g[i][j]][i][j]);
			max = std::max(max, dp[g[i][j]][j]);
		}
	}


	std::cout << max << "\n";

	return 0;
}