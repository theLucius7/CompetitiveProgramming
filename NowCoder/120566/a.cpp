#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

constexpr real eps = 1E-18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	real w;
	std::cin >> n >> w;

	std::vector<real> x(n), y(n);
	for (int i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}

	auto check = [&](real t) {
		i64 sum = 0;
		for (int i = 0; i < n; i++) {
			i64 ny = std::min(t * x[i], y[i]);
			sum += y[i] - ny; 
		}
		return sum <= w;
	};

	real lo = 0, hi = 0; // k = y / x
	for (int i = 0; i < n; i++) {
		hi = std::max(hi, y[i] / x[i]);
	}

	for (int i = 0; i < 200; i++) {
	    real x = (lo + hi) / 2;
	    if (check(x)) {
	        hi = x;
	    } else {
	        lo = x;
	    }
	}

	real ans = 0;
	for (int i = 0; i < n; i++) {
		i64 ny = std::min(hi * x[i],  y[i]);
		ans += std::hypot(x[i], (real)ny);
	}
	std::cout << std::fixed << std::setprecision(12) << ans << "\n";

	return 0;
}