#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, d;
	std::cin >> n >> m >> d;

	std::cout << (n / (d / m + 1) + (n % (d / m + 1) != 0)) << "\n";
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