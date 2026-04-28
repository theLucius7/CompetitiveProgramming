#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1E9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<i64> dp(n + 1);
	dp[1] = 1, dp[2] = 2, dp[3] = 5;
	i64 sum = 1;
	for (int i = 4; i <= n; i++) {
		sum += dp[i - 3];
		sum %= P;
		dp[i] = dp[i - 1] + dp[i - 2] + 2 * sum;
		dp[i] %= P;
	}
	std::cout << dp[n] << "\n";

	return 0;
}