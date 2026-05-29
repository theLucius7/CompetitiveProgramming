#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int k, x;
	std::cin >> k >> x;

	std::cout << 1LL * (1LL << k) * x << "\n";
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