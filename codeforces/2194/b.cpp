#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 x, y;
	std::cin >> n >> x >> y;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> b = a;
	std::vector<int> cnt(n);
	for (int i = 0; i < n; i++) {
		cnt[i] = a[i] / x;
		a[i] %= x;
	}

	i64 all = std::accumulate(cnt.begin(), cnt.end(), 0LL);
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans = std::max(ans, 1LL * (all - cnt[i]) * y + b[i]);
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