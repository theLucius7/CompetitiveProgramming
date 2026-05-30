#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<i64> A(N), B(N), C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}

	std::vector<std::array<i64, 3>> dp(N);
	dp[0][0] = A[0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i - 1][0] + A[i];;
		dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) + B[i];	
		if (i > 1) {
			dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]) + C[i];
		}	
	}

	std::cout << dp[N - 1][2] << "\n";


	return 0;
}