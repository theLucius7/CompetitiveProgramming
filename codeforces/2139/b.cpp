#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 m;
	std::cin >> n >> m;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end(), std::greater<int>());

	i64 ans = 0;
	for (int i = 0; i < std::min(m, (i64)n); i++) {
		ans += (m - i) * a[i];
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
