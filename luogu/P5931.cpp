#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

void solve() {
	real H, h, D;
	std::cin >> H >> h >> D;

	real ans = D / H * h;

	real x = std::sqrt(D * (H - h));
	if (x <= D && x >= D / H * (H - h)) {
		ans = std::max(ans, D + H - 2 * std::sqrt(D * (H - h)));
	} else {
		ans = std::max(ans, h);
	}
	std::cout << std::fixed << std::setprecision(7) << ans << "\n";
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