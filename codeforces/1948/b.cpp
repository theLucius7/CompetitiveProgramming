#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

#define int long long

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int l = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 10 && l <= a[i] / 10 && a[i] / 10 <= a[i] % 10) {
			l = a[i] % 10;
		} else if (a[i] >= l) {
			l = a[i];
		} else {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}