#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

#define int long long

void solve() {
	std::string x, y;
	std::cin >> x >> y;

	const int n = x.size();

	int l = n;
	for (int i = 0; i < n; i++) {
		if (x[i] != y[i]) {
			l = i;
			break;
		}
	}

	if (l < n && x[l] < y[l]) {
		// char c = x[l];
		// x[l] = y[l];
		// y[l] = c;

		std::swap(x[l], y[l]);
		// std::cout << x[l] << " " << y[l] << " " << l <<  "?\n";
	}

	for (int i = l + 1; i < n; i++) {
		if (x[i] > y[i]) {
			// char c = x[i];
			// x[i] = y[i];
			// y[i] = c;
			std::swap(x[i], y[i]);
		}
	}
	std::cout << x << "\n" << y << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}