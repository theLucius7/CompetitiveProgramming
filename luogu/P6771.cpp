#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::array<int, 3>> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	std::sort(a.begin(), a.end(), [&](auto x, auto y) {
		return x[1] < y[1];
	});

	int H = a.back()[1];

	std::vector<bool> dp(H + 1);
	dp[0] = true;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		std::vector<int> cnt(H + 1);
		auto [h, aa, c] = a[i];
		for (int j = h; j <= aa; j++) {
			if (!dp[j] && dp[j - h] && cnt[j - h] < c) {
				dp[j] = 1;
				cnt[j] = cnt[j - h] + 1;
				ans = std::max(ans, j);
			}
		}
	}

	std::cout << ans << "\n";


	return 0;
}