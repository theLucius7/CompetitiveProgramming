#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	if (n % 2 == 0) {
		std::cout << -1 << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		std::cout << (2 * i - 1) % n + 1 << " \n"[i == n];
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