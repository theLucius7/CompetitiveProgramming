#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> dp(n + 1);
	dp[n] = 0;

	for (int i = n - 1; i >= 0; i--) {
		dp[i] = dp[i + 1] + 1;
		if (i + a[i] < n) {
			dp[i] = std::min(dp[i], dp[i + a[i] + 1]);
		}
	}
	std::cout << dp[0] << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}