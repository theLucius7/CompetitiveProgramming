#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<u64> a(n);

	std::vector<u64> d1(n + 2), d2(n + 2);

	for (int i = 0; i < m; i++) {
		int l, r, s, e;
		std::cin >> l >> r >> s >> e;
		l--, r--;

		u64 d = (e - s) / (r - l);

		d2[l] += s;
		d2[l + 1] += d - s;

		d2[r + 1] -= d + e;
		d2[r + 2] += e;
	}



	for (int i = 0; i < n; i++) {
		if (i == 0) {
			d1[i] += d2[i];
		} else {
			d1[i] += d2[i] + d1[i - 1];
		}
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			a[i] += d1[i];
		} else {
			a[i] += d1[i] + a[i - 1];
		}
	}

	u64 sum = 0, max = 0;
	for (int i = 0; i < n; i++) {
		sum ^= a[i];
		max = std::max(max, a[i]);
	}

	std::cout << sum << " " << max << "\n";


	return 0;
}