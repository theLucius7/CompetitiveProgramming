#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;

void solve() {
	i64 a, b;
	std::cin >> a >> b;

	if ((i128)a * b % 2 == 1) {
		std::cout << a * b + 1 << "\n";
	} else {
		if (b % 2 == 1) {
			std::cout << -1 << "\n";
		} else {
			if (b % 4 == 2) {
				std::cout << (a % 2 == 0 ? 2 + a * b / 2 : -1) << "\n";
			} else if (b % 4 == 0) {
				std::cout << 2 + a * b / 2 << "\n";
			}
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