#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 y, x;
	std::cin >> y >> x;

	if (y >= x) {
		if (y % 2 == 0) {
			std::cout << y * y - x + 1 << "\n";
		} else {
			std::cout << (y - 1) * (y - 1) + x << "\n";
		}
	} else {
		if (x % 2 == 1) {
			std::cout << x * x - y + 1 << "\n";
		} else {
			std::cout << (x - 1) * (x - 1) + y << "\n";
		}
	}
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