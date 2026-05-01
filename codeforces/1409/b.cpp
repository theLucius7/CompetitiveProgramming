#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b, x, y, n;
	std::cin >> a >> b >> x >> y >> n;

	i64 s = std::max(x + y, a + b - n);
	i64 u = std::min(std::max(a - n, x), std::max(b - n, y));
	std::cout << u * (s - u) << "\n";
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