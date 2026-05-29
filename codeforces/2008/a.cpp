#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b;
	std::cin >> a >> b;

	if ((a == 0 && b % 2 == 1)) {
		std::cout << "NO\n";
		return;
	}

	std::cout << (((a * 1 + b * 2) % 2 == 0) ? "YES" : "NO") << "\n";
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