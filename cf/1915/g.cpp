#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<std::pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		u--, v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	std::vector<int> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> q;
	q.emplace(0, 0);

	std::vector<i64> dis(n * n, -1LL);

	while (!q.empty()) {
		auto [d, x] = q.top();
		q.pop();

		if (dis[x] != -1) {
			continue;
		}
		dis[x] = d;

		int c = x / n, b = x % n;
		if (c == n - 1) {
			std::cout << d << "\n";
			return;
		}

		q.emplace(d, c * n + c);
		for (auto [y, w] : adj[c]) {
			q.emplace(d + s[b] * w, y * n + b);
		}
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