#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n;
	std::cin >> n;

	std::vector<int> g(n);
	for (int i = 0; i < n; i++) {
		std::cin >> g[i];
	}

	std::sort(g.begin(), g.end());

	i64 ans = 0;
	if (n % 2 == 0) {
		for (int i = 1; i < n; i += 2) {
			ans += g[i];
		}
	} else {
		for (int i = 0; i < n; i += 2) {
			ans += g[i];
		}
	}
	std::cout << ans << "\n";
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