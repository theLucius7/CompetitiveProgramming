#include <bits/stdc++.h>

using i64 = long long;

#define int long long

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	std::map<int, i64> cnt;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		cnt[a[i]]++;
	}

	i64 sum = 0, ans = 0;
	for (auto [x, v] : cnt) {
		ans += (v >= 3 ? 1LL * v * (v - 1) / 2 * (v - 2) / 3 : 0) + (v >= 2 ? 1LL * v * (v - 1) / 2 * sum : 0);
		sum += v;
	}
	std::cout << ans << "\n";
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