#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;

	std::cout << (std::max({a, b, c}) - std::min({a, b, c}) >= 2 ? "NO" : "YES") << "\n";
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