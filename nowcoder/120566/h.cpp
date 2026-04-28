#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> B[i];
	}

	std::vector<bool> dp(5000);
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		std::vector<bool> ndp(5000);
		for (int x = 0; x <= 2048; x++) {
			if (dp[x]) {
				ndp[x ^ B[i]] = true;
				ndp[std::max(0, x - A[i])] = true;
			}
		}
		dp = ndp;
	}

	for (int x = 2048; x >= 0; x--) {
		if (dp[x]) {
			std::cout << x << "\n";
			return 0;
		}
	}

	return 0;
}