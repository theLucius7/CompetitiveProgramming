#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	for (int i = 40; i >= 0; i--) {
		i64 x = ans | (1LL << i);
		int cnt = 0;
		for (int j = 0; j < 2 * n; j++) {
			if ((a[j] & x) == x) {
				cnt++;
			}
		}
		if (cnt >= n) {
			ans = x;
		}
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