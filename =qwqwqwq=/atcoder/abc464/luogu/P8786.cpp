#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1E9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<std::vector<int>>> dp(N + M + 1, std::vector<std::vector<int>>(M + 1, std::vector<int>(M + 1)));
	dp[0][0][2] = 1;

	for (int i = 0; i < N + M; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k <= M; k++) {
				if (2 * k <= M) {
					dp[i + 1][j][2 * k] += dp[i][j][k];
					dp[i + 1][j][2 * k] %= P;
				}
				dp[i + 1][j + 1][k - 1] += dp[i][j][k];
				dp[i + 1][j + 1][k - 1] %= P;

			}
		}
	}

	std::cout << dp[N + M][M][0] << "\n";

	return 0;
}