#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18 + 1;

void solve() {
	i64 n, h, x, y, a, b;
	std::cin >> n >> h >> x >> y >> a >> b;

	std::vector<std::array<i64, 2>> aim{
		{1, 1}, {1, h}, {n, 1}, {n, h}
	};

	i64 ans = inf;
	for (int i = 0; i < 4; i++) {
		i64 dx = std::abs(x - aim[i][0]), dy = std::abs(y - aim[i][1]);
		if (dx % a != 0 || dy % b != 0 || (dx / a - dy / b) % 2 != 0) {
			continue;
		}
		ans = std::min(ans, std::max(dx / a, dy / b));
	}

	std::cout << (ans == inf ? -1 : ans) << "\n";
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