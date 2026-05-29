#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;

	std::vector<std::vector<std::pair<int, i64>>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});

		if (a[u] != a[v]) {
			ans += w;
		}
	}

	while (q--) {
		int v, x;
		std::cin >> v >> x;
		v--;

		i64 pre = 0, now = 0;
		for (auto [u, w] : adj[v]) {
			pre += (a[u] != a[v] ? w : 0);
			now += (a[u] != x ? w : 0);
		}
		a[v] = x;

		ans = ans - pre + now;
		std::cout << ans << "\n";
	}
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