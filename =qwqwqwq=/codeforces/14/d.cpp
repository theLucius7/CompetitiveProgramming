#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	std::vector<int> d(n), dia(n);
	auto dfs = [&](this auto &&self, int x, int p) -> void {
		d[x] = dia[x] = 0;
		for (auto y : adj[x]) {
			if (y != p) {
				self(y, x);
				dia[x] = std::max({dia[x], dia[y], d[x] + d[y] + 1});
				d[x] = std::max(d[x], d[y] + 1);
			}
		}
	};

	int max = 0;
	for (int x = 0; x < n; x++) {
		for (auto y : adj[x]) {
			if (x < y) {
				dfs(x, y);
				dfs(y, x);
				max = std::max(max, dia[x] * dia[y]);
			}
		}
	}

	std::cout << max << "\n";


	return 0;
}