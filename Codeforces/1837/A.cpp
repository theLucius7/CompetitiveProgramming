#include <bits/stdc++.h>

void solve() {
	int x, k;
	std::cin >> x >> k;

	if (x % k != 0) {
		std::cout << 1 << "\n";
		std::cout << x << "\n";
	} else {
		std::cout << 2 << "\n";
		std::cout << x - k - 1 << " " << k + 1 << "\n";
	}
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}