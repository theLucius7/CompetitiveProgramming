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

	std::vector<int> dp(26, inf);
	std::vector<int> cost{0, 1, 1, 1, 1, 2};
	for (int i = 0; i < 6; i++) {
		int x = s[i][0] - 'A';
		dp[x] = std::min(dp[x], cost[i]);
	}

	for (int i = 1; i < 16; i++) {
		std::vector<int> minv(26, inf);
		for (int y = 0; y < 26; y++) {
			int ny = (y == 'Q' - 'A' ? 'U' - 'A' : y);
			minv[ny] = std::min(minv[ny], dp[y]);
		}
		for (int y = 1; y < 26; y++) {
			minv[y] = std::min(minv[y], minv[y - 1]);
		}

		std::vector<int> ndp(26, inf);
		for (int j = 0; j < 6; j++) {
			int x = s[j][i] - 'A';
			ndp[x] = std::min(ndp[x], minv[x] + cost[j]);
		}
		dp = std::move(ndp);
	}

	int ans = *std::min_element(dp.begin(), dp.end());
	if (ans == inf) {
		std::cout << "impossible\n";
	} else {
		std::cout << ans << "\n";
	}


	return 0;
}