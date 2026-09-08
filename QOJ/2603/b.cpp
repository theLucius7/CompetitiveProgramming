#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::string> s(6);
	for (int i = 0; i < 6; i++) {
		std::cin >> s[i];
	}

	int n = 16;
	std::vector dp(n, std::vector<int>(26, inf));
	for (int i = 0; i < 6; i++) {
		if (i == 0) {
			dp[0][s[i][0] - 'A'] = std::min(dp[0][s[i][0] - 'A'], 0);
		} else if (i >= 1 && i <= 4) {
			dp[0][s[i][0] - 'A'] = std::min(dp[0][s[i][0] - 'A'], 1);
		} else {
			dp[0][s[i][0] - 'A'] = std::min(dp[0][s[i][0] - 'A'], 2);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			int x = s[j][i] - 'A';
			if (j == 0) {
				for (int y = 0; y < 26; y++) {
					int ny = y;
					if (ny == 'Q' - 'A') {
						ny = 'U' - 'A';
					}
					if (ny <= x) {
						dp[i][x] = std::min(dp[i][x], dp[i - 1][y] + 0);
					}
				}
			} else if (j >= 1 && j <= 4) {
				for (int y = 0; y < 26; y++) {
					int ny = y;
					if (ny == 'Q' - 'A') {
						ny = 'U' - 'A';
					}
					if (ny <= x) {
						dp[i][x] = std::min(dp[i][x], dp[i - 1][y] + 1);
					}
				}
			} else {
				for (int y = 0; y < 26; y++) {
					int ny = y;
					if (ny == 'Q' - 'A') {
						ny = 'U' - 'A';
					}
					if (ny <= x) {
						dp[i][x] = std::min(dp[i][x], dp[i - 1][y] + 2);
					}
				}
			}
		}
	}

	int min = inf;
	for (int i = 0; i < 26; i++) {
		min = std::min(min, dp[n - 1][i]);
	}

	if (min == inf) {
		std::cout << "impossible\n";
	} else {
		std::cout << min << "\n";
	}



	return 0;
}
