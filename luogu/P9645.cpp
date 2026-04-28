#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

constexpr i64 mod = 1E9 + 7;

void solve() {
	i64 x, y, z;
	std::cin >> x >> y >> z;

	i64 k = x + y - z;

	if (y == 0) {
		if (x == z) {
			std::cout << x + 1 << "\n";
		} else {
			std::cout << -1 << "\n";
		}
		return;
	}

	if (x + y == z) {
		std::cout << z + 1 << "\n";
		return;
	}

	if (x + y < z || x >= k || z >= k) {
		std::cout << -1 << "\n";
	} else {
		std::cout << k << "\n";
	}
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}