#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}

	std::vector<int> sum(2 * N + 1);
	for (int i = 0; i < 2 * N; i++) {
		sum[i + 1] = sum[i] + a[i % N];
	}

	constexpr int inf = 1E7;
	std::vector dp(2 * N, std::vector<std::array<int, 2>>(2 * N, {inf, -inf}));
	for (int i = 0; i < 2 * N; i++) {
		dp[i][i] = {0, 0};
	}


	for (int l = 2 * N - 1; l >= 0; l--) {
		for (int r = l + 1; r < std::min(2 * N, l + N); r++) {
			for (int m = l; m < r; m++) {
				int cost = sum[r + 1] - sum[l];
				dp[l][r][0] = std::min(dp[l][r][0], dp[l][m][0] + dp[m + 1][r][0] + cost);
				dp[l][r][1] = std::max(dp[l][r][1], dp[l][m][1] + dp[m + 1][r][1] + cost);
			}
		}
	}

	int min = inf, max = -inf;
	for (int l = 0; l < N; l++) {
		min = std::min(min, dp[l][l + N - 1][0]);
		max = std::max(max, dp[l][l + N - 1][1]);
	}
	std::cout << min << "\n" << max << "\n";


	return 0;
}