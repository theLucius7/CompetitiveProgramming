#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	std::cout << ((std::max(a, b) <= 2 * (std::min(a, b) + 1) && std::max(c - a, d - b) <= 2 * (std::min(c - a, d - b) + 1)) ? "YES" : "NO") << "\n"; 
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}