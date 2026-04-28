#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int L, R, D, U;
	std::cin >> L >> R >> D >> U;

	auto get = [&](int a, int b) {
		if (a > b) {
			std::swap(a, b);
		}
		return 1LL * (a / 2 + 1) * (a / 2 * 2 + 1) + 1LL * (b / 2 - a / 2) * (a + 1);
	};

	std::vector<std::array<int, 2>> x, y;
	if (L > 0) {
		x.push_back({R, 1});
		x.push_back({L - 1, -1});
	} else if (R < 0) {
		x.push_back({-L, 1});
		x.push_back({-R - 1, -1});
	} else {
		x.push_back({R, 1});
		x.push_back({-L, 1});
		x.push_back({0, -1});
	}
	if (D > 0) {
		y.push_back({U, 1});
		y.push_back({D - 1, -1});
	} else if (U < 0) {
		y.push_back({-D, 1});
		y.push_back({-U - 1, -1});
	} else {
		y.push_back({U, 1});
		y.push_back({-D, 1});
		y.push_back({0, -1});
	}

	i64 ans = 0;
	for (auto [a, c] : x) {
		for (auto [b, d] : y) {
			ans += get(a, b) * c * d;
		}
	}
	std::cout << ans << "\n";

	return 0;
}