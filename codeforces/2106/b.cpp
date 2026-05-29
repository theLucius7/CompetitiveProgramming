#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int x;
	std::cin >> x;

	for (int i = 0; i < x; i++) {
		std::cout << i << " ";
	}

	for (int i = x + 1; i < n; i++) {
		std::cout << i << " ";
	}

	if (x != n) {
		std::cout << x;
	}
	std::cout << "\n";
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