#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		max = std::max(max, a[i]);
	}

	auto check = [&](int x) {
		if (x == 0) {
			return true;
		}

		std::vector<bool> b(x);
		int cnt = 0, res = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < x && !b[a[i]]) {
				cnt++;
				b[a[i]] = true;
			}
			if (cnt == x) {
				res++;
				cnt = 0;
				std::fill(b.begin(), b.end(), false);
			}
		}
		return res >= k;
	};

	int lo = 0, hi = max + 2;
	while (lo < hi) {
	    int m = (lo + hi + 1) / 2;
	    if (check(m)) {
	        lo = m;
	    } else {
	        hi = m - 1;
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