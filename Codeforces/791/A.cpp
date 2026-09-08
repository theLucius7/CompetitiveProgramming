#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b;
	std::cin >> a >> b;

	for (int ans = 0; ; ans++) {
		if (a > b) {
			std::cout << ans << "\n";
			return;
		}
		a *= 3;
		b *= 2;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}