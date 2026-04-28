#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::string> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> dp(n, std::vector<int>(2));
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dp[i][0] = a[0].size();
			dp[i][1] = a[0].size();
		} else {
			dp[i][0] = std::min(dp[i - 1][0] + a[i].size() + (a[i - 1].back() == a[i][0] ? -1 : 0), dp[i - 1][1] + a[i].size() + (a[i - 1][0] == a[i][0] ? -1 : 0));
			dp[i][1] = std::min(dp[i - 1][0] + a[i].size() + (a[i - 1].back() == a[i].back() ? -1 : 0), dp[i - 1][1] + a[i].size() + (a[i - 1][0] == a[i].back() ? -1 : 0));
		}
	}

	std::cout << std::min(dp[n - 1][0], dp[n - 1][1]) << "\n";

	return 0;
}