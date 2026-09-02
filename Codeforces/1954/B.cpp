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

	int last = -1;
	int ans = inf;
	for (int i = 0; i <= n; i++) {
		if (i == n || a[i] != a[0]) {
			ans = std::min(ans, i - last - 1);
			last = i;
		}
	}
	std::cout << (ans == n ? -1 : ans) << "\n";
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