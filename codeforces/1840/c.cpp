#include <bits/stdc++.h>

using int64 = long long;

void solve() {
	int n, k, q;
	std::cin >> n >> k >> q;
		
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int suf = 0;
	int64 ans = 0;
	for (auto x : a) {
		suf = (x <= q) ? suf + 1 : 0;
		ans += std::max(suf - k + 1, 0);
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