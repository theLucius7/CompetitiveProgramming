#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, T;
	std::cin >> H >> T;

	int n;
	std::cin >> n;

	std::vector<std::array<int, 3>> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	std::vector dp(H + 1, std::vector<int>(T + 1));
	for (int i = 0; i < n; i++) {
		for (int h = H; h >= a[i][0]; h--) {
			for (int t = T; t >= a[i][1]; t--) {
				dp[h][t] = std::max(dp[h][t], dp[h - a[i][0]][t - a[i][1]] + a[i][2]);
			}
		}
	}
	std::cout << dp[H][T] << "\n";


	return 0;
}