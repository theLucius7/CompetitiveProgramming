#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	long double ans = 0;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			ans -= 1.0 * i / (2 * i - 1);
		} else {
			ans += 1.0 * i / (2 * i - 1);
		}
	}

	std::cout << std::fixed << std::setprecision(3) << ans << "\n";

	return 0;
}