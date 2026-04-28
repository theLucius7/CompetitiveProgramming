#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	auto dist = [&](std::pair<double, double> a, std::pair<double, double> b) -> double {
		return std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
	};

	std::vector<std::array<double, 2>> C(2);
	std::array<double, 2> R;
	for (int i = 0; i < 2; i++) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		C[i][0] = (a + c) / 2.0;
		C[i][1] = (b + d) / 2.0;
		R[i] = dist({a, b}, {c, d}) / 2.0;
	}
	
	std::cout << std::fixed << std::setprecision(10) << std::fabs(C[1][0] - C[0][0]) + std::fabs(C[0][1] - C[1][1]) - std::sqrt(2.0) * R[1] << "\n";

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}