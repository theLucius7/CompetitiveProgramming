#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	auto check = [&](int x) {
		int cnta = 0;
		for (int i = 0; i < n; i++) {
			if (x >= a[i]) {
				cnta++;
			}
		}

		int cntb = 0;
		for (int i = 0; i < m; i++) {
			if (x <= b[i]) {
				cntb++;
			}
		} 
		
		// std::cerr << std::lower_bound(a.begin(), a.end(), x) - a.begin() << " " << cnta << "\n";
		// return cnta >= cntb;


		return std::upper_bound(a.begin(), a.end(), x) - a.begin() >= b.end() - std::lower_bound(b.begin(), b.end(), x);
	};

	int lo = 1, hi = 1E9 + 1;
	while (lo < hi) {
	    int m = (lo + hi) / 2;
	    if (check(m)) {
	        hi = m;
	    } else {
	        lo = m + 1;
	    }
	}
	std::cout << lo << "\n";

	return 0;
}