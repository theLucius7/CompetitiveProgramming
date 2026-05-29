#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x;
	std::cin >> x;

	if (x == 1) {
		std::cout << "YES\n";
		std::cout << 1 << "\n";
	} else if (x == 3) {
		std::cout << "YES\n";
		std::cout << "1 2 3\n";
	} else {
		std::cout << "NO\n";
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