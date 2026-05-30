#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// int n = 30;

	// std::vector<std::vector<int>> dp(31, std::vector<int>(11));
	// dp[0][0] = 1;
	// for (int i = 1; i <= 30; i++) {
	// 	for (int j = 0; j <= 10; j++) {
	// 		if (j == 0) {
	// 			for (int k = 0; k <= 9; k++) {
	// 				dp[i][j] += dp[i - 1][k];
	// 			}
	// 		} else {
	// 			dp[i][j] += dp[i - 1][j - 1];
	// 		}
	// 	}
	// }

	// i64 sum = 0;
	// for (int i = 1; i <= 30; i++) {
	// 	sum += dp[i][7];
	// }
	// std::cout << sum << "\n";

	char type;
	std::cin >> type;

	if (type == 'A') {
		std::cout << 4430091 << "\n";
	} else {
		std::cout << 8335366 << "\n";
	}


	return 0;
}