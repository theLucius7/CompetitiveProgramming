#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> dp(n);
	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		dp[i] = std::max(a[i], dp[i - 1] + a[i]);
	}

	std::cout << *max_element(dp.begin(), dp.end()) << "\n";

	return 0;
}