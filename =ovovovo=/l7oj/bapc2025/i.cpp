#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

#define int long long

constexpr int inf = 1E18;
constexpr real eps = 1E-10;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, w;
	std::cin >> n >> w;

	std::vector<real> p(n), t(n);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i] >> t[i];
	}

	auto check = [&](real m) {
	    real sum = 0;
	    for (int i = 0; i < n; i++) {
	    	if (m > 2 * t[i]) {
	    		sum += 1.L * (m - 2 * t[i]) * p[i];
	    	}
	    }
	    return sum >= 1.L * w;
	};

	real lo = 0;
	real hi = 1E12;
	while (hi - lo > std::max(1.L, lo) * eps) {
	    real x = (lo + hi) / 2;
	    if (check(x)) {
	        hi = x;
	    } else {
	        lo = x;
	    }
	}

	std::cout << std::fixed << std::setprecision(12) << lo << "\n";

	return 0;
}