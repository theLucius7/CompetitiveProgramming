#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 g = std::llabs(a[0] - k);
	for (int i = 1; i < n; i++) {
		g = std::gcd(g, a[i] - a[i - 1]);
	}

	if (g == 0) {
		std::cout << 0 << "\n";
		return;
	}

	i64 v = a[0] < k ? k - g : k + g;
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		i64 res = (a[i] - v) / (v - k);
		if (res < 0) {
			std::cout << -1 << "\n";
			return;
		}
		ans += res;
	}
	std::cout << ans << "\n";
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