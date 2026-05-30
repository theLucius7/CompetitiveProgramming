#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k, q;
	std::cin >> n >> k >> q;

	std::vector<std::vector<int>> g(k, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			std::cin >> g[j][i];
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 1; j < n; j++) {
			g[i][j] |= g[i][j - 1];
		}
	}

	while (q--) {
		int m;
		std::cin >> m;

		int l = 0, r = n;
		while (m--) {
			int x;
			char o;
			int c;
			std::cin >> x >> o >> c;
			x--;

			if (o == '>') {
				l = std::max(l, (int)(std::upper_bound(g[x].begin(), g[x].end(), c) - g[x].begin()));
			} else {
				r = std::min(r, (int)(std::lower_bound(g[x].begin(), g[x].end(), c) - g[x].begin()) - 1);
			}
		}
		std::cout << ((l >= 0 && l < n && r >= 0 && r <= n && l <= r) ? l + 1 : -1) << "\n";
	}

	return 0;
}
