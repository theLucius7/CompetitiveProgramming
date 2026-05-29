#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> P(N + 1);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
	}

	std::sort(P.begin(), P.end());

	int k = std::lower_bound(P.begin(), P.end(), 0) - P.begin();

	constexpr i64 inf = 1E18;

	std::vector<std::array<i64, 2>> dp(N + 1, {inf, inf});
	dp[k] = {0, 0};
	for (int l = k; l >= 0; l--) {
		std::vector<std::array<i64, 2>> ndp(N + 1, {inf, inf});
		if (l == k) {
			ndp[k] = {0, 0};
		}
		for (int r = k; r <= N; r++) {
			int cnt = N - r + l + 1;
			if (l < k) {
				ndp[r][0] = std::min(dp[r][0] + 1LL * (P[l + 1] - P[l]) * cnt, dp[r][1] + 1LL * (P[r] - P[l]) * cnt);
			}
			if (r > k) {
				ndp[r][1] = std::min(ndp[r - 1][0] + 1LL * (P[r] - P[l]) * cnt, ndp[r - 1][1] + 1LL * (P[r] - P[r - 1]) * cnt);
			}
		}
		dp = std::move(ndp);
	}

	std::cout << std::min(dp[N][0], dp[N][1]) << "\n";

	return 0;
}