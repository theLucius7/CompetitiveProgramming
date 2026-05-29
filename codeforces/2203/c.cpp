#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 s, m;
	std::cin >> s >> m;

	if ((s > 0 && m == 0) || s == 0 || s % (m & -m) != 0) {
		std::cout << -1 << "\n";
		return;
	}

	std::vector<i64> base;
	for (int i = 0; i < 62; i++) {
		if ((m >> i) & 1) {
			base.push_back(1LL << i);
		}
	}

	auto check = [&](i64 x) {
		i64 sum = s;
		for (int i = base.size() - 1; i >= 0; i--) {
			sum -= std::min(x, sum / base[i]) * base[i];
		}
		return sum == 0;
	};

	i64 lo = 1, hi = s;
	while (lo < hi) {
	    i64 m = (lo + hi) / 2;
	    if (check(m)) {
	        hi = m;
	    } else {
	        lo = m + 1;
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