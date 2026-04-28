#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int p, k;
	std::cin >> p >> k;

	std::cout << k / p * (p - 1) + k % p << "\n";
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