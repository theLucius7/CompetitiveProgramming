#include <bits/stdc++.h>

using i64 = long long;

#define int long long

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::vector<std::pair<int, int>>> adj(n);
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--, v--;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
		sum += c;
	}

	std::vector<int> d(n), dia(n);
	[&](this auto &&self, int x, int p) -> void {
		d[x] = dia[x] = 0;
		for (auto [y, c] : adj[x]) {
			if (y != p) {
				self(y, x);
				dia[x] = std::max({dia[x], dia[y], d[x] + d[y] + c});
				d[x] = std::max(d[x], d[y] + c);
			}
		}
	}(0, -1);

	std::cout << 2 * sum - dia[0] << "\n";

	return 0;
}