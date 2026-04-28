#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::tuple<i64, i64, i64>> p(n);
	for (int i = 0; i < n; i++) {
		i64 w, v, c;
		std::cin >> w >> v >> c;
		p[i] = {w, v, c};
	}

	std::sort(p.begin(), p.end(), [](const std::tuple<i64, i64, i64> a, const std::tuple<i64, i64, i64> b) {
		return std::get<0>(a) * std::get<2>(b) > std::get<0>(b) * std::get<2>(a);
	});
	
	i64 sum = 0, ans = 0;
	for (auto [w, v, c] : p) {
		ans += v - sum * c;
		sum += w;
	}
	std::cout << ans << "\n";

	return 0;
}

