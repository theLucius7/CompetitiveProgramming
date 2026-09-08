#include <bits/stdc++.h>

#define int long long

using i64 = long long;

void solve() {
	int k, n, w;
	std::cin >> k >> n >> w;

	int cost = (k + w * k) * w / 2;
	std::cout << std::max(0LL, cost - n) << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}