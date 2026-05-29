#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::array<i64, 2> dp{};	
	for (int i = 0; i < N; i++) {
		i64 X, Y;
		std::cin >> X >> Y;

		if (X == 0) {
			dp[0] = std::max({dp[0] + Y, dp[1] + Y, dp[0]});
		} else {
			dp[1] = std::max({dp[0] + Y, dp[1]});
		}
	}

	std::cout << std::max(dp[0], dp[1]) << "\n";


	return 0;
}