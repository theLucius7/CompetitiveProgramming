#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b, c, d;
	std::cin >> a >> b >> c >> d;

	i64 cnt = 0;
	for (int y = 1; y * b < c * d; y++) {


		if (a * c * y % (c * d - b * y) == 0) {
			cnt++;
		}
	}
	std::cout << cnt << "\n";
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