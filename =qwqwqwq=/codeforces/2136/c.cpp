#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> dp(n + 1);
	std::vector<std::vector<int>> pos(n + 1);
	for (int i = 0; i < n; i++) {
		pos[a[i]].push_back(i);

		dp[i + 1] = dp[i];
		if (pos[a[i]].size() >= a[i]) {
			dp[i + 1] = std::max(dp[i + 1], dp[pos[a[i]][pos[a[i]].size() - a[i]]] + a[i]);
		}
	}
	std::cout << dp[n] << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}