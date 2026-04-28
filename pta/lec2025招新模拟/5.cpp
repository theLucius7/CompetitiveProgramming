#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	double x;
	std::cin >> x;


	double ans;
	if (x >= 0) {
		ans = std::sqrt(x);
	} else {
		ans = pow(x + 1, 2) + 2 * x + 1 / x;
	}

	std::cout << std::fixed << std::setprecision(2) << "f(" << x << ")" << " = " << ans << "\n";

	return 0;
}