#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int y, m, d;
	char c;
	std::cin >> y >> c >> m >> c >> d;

	std::array<int, 13> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
		days[2] = 29;
	}

	int ans = d;
	for (int i = 1; i < m; i++) {
		ans += days[i];
	}
	std::cout << ans << "\n";

	return 0;
}