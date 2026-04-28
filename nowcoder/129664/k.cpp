#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 sum = 0;
	i64 a, b, c, d;
	while (std::cin >> a >> b >> c >> d && (a || b || c || d)) {
		if (d == 1) {
			sum += a * 3600 + b * 60 + c;
		}
	}

	real ans = 1.L * sum / 3600;

	if (ans <= 24.0) {
		std::cout << std::fixed << std::setprecision(2) << ans << "\n";
		std::cout << "Yes!\n";
	} else {
		std::cout << "No!\n";
	}


	return 0;
}