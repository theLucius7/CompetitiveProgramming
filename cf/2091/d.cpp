#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, m, k;
	std::cin >> n >> m >> k;

	auto check = [&](i64 x) {
		return (m / (x + 1) * x + m % (x + 1)) * n >= k;
	};

	int lo = 1, hi = 1E9 + 10;
	while (lo < hi) {
	    i64 x = (lo + hi) / 2;
	    if (check(x)) {
	        hi = x;
	    } else {
	        lo = x + 1;
	    }
	}
	std::cout << lo << "\n";
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