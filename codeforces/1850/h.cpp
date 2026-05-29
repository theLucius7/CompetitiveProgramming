#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<std::pair<int, i64>>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		i64 d;
		std::cin >> a >> b >> d;
		a--, b--;
		adj[a].emplace_back(b, d);
		adj[b].emplace_back(a, -d);
	}

	bool ok = true;
	std::vector<bool> vis(n);
	std::vector<i64> w(n);
	auto dfs = [&](auto self, int x) -> void {
		for (auto [y, d] : adj[x]) {
			if (!vis[y]) {
				vis[y] = true;
				w[y] = w[x] + d;
				self(self, y);
			} else {
				if (w[y] != w[x] + d) {
					ok = false;
				}
			}
		}
	};
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(dfs, i);
		}
	}

	std::cout << (ok ? "YES" : "NO") << "\n";
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