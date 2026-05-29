#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> a(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cin >> a[i][j];
		}
	}

	std::vector<std::vector<int>> dp(n, std::vector<int>(n));
	dp[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
			} else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + a[i][j];
			} else {
				dp[i][j] = std::max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
			}
		}
	}
	std::cout << *max_element(dp[n - 1].begin(), dp[n - 1].end) << "\n";

	return 0;
}