#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::vector<int> d(n), dia(n);
	[&](this auto &&self, int x, int p) -> void {
		d[x] = dia[x] = 0;
		for (auto y : adj[x]) {
			if (y != p) {
				self(y, x);
				dia[x] = std::max({dia[x], dia[y], d[x] + d[y] + 1});
				d[x] = std::max(d[x], d[y] + 1);
			}
		}
	}(0, -1);

	std::cout << dia[0] << "\n";

	return 0;
}