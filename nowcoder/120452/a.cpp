#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1E9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	std::vector<std::vector<i64>> dp(n, std::vector<i64> (m));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i - 1 >= 0 && s[i - 1][j] != 'R') {
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= P;
			} 
			if (j - 1 >= 0 && s[i][j - 1] != 'D') {
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= P;
			}
		}
	}
	std::cout << dp[n - 1][m - 1] << "\n";

	return 0;
}