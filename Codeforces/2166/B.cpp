#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	long double a, b, n;
	std::cin >> a >> b >> n;

	std::cout << (n > 1 && b > a / n && b < a ? 2 : 1) << "\n";
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