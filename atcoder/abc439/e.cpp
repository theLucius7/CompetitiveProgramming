#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		std::cin >> v[i].first >> v[i].second;
	}

	std::sort(v.begin(), v.end(), [&](auto x, auto y) {
		if (x.first != y.first) {
			return x.first < y.first;
		} else {
			return x.second > y.second;
		}
	});

	std::vector<int> dp;
	for (auto [A, B] : v) {
		int i = std::lower_bound(dp.begin(), dp.end(), B) - dp.begin();
		if (i == dp.size()) {
			dp.push_back(B);
		} else {
			dp[i] = B;
		}
	}

	std::cout << dp.size() << "\n";

	return 0;
}