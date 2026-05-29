#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector dp(n + 1, std::vector<int>(k + 1, inf));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int min = a[i];
		for (int j = 0; i + j < n && j <= k; j++) {
			min = std::min(min, a[i + j]);
			for (int x = 0; x + j <= k; x++) {
				dp[i + j + 1][x + j] = std::min(dp[i + j + 1][x + j], dp[i][x] + min * (j + 1));
			}
		}
	}

	std::cout << *std::min_element(dp[n].begin(), dp[n].end()) << "\n";

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}