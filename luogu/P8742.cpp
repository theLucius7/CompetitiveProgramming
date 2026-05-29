#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> W(N);
	for (int i = 0; i < N; i++) {
		std::cin >> W[i];
	}
	int sum = std::accumulate(W.begin(), W.end(), 0);

	std::vector<int> dp(sum + 1);
	dp[0] = true;
	for (int i = 0; i < N; i++) {
		auto ndp = dp;
		for (int w = 0; w <= sum; w++) {
			if (w + W[i] <= sum) {
				ndp[w + W[i]] |= dp[w];
			}
			ndp[w] |= dp[w];
			ndp[std::abs(w - W[i])] |= dp[w];
		}
		dp = std::move(ndp);
	}

	std::cout << std::count(dp.begin() + 1, dp.end(), true) << "\n";


	return 0;
}