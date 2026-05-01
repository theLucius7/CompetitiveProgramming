#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, t;
	std::cin >> n >> t;

	std::vector<std::vector<std::pair<int, int>>> adj(n);
	for (int i = 0; i < t; i++) {
		int m;
		std::cin >> m;

		for (int j = 0; j < m; j++) {
			int u, v;
			std::cin >> u >> v;
			u--;
			v--;
			adj[u].emplace_back(v, i);
			adj[v].emplace_back(u, i);
		}
	}

	int k;
	std::cin >> k;

	std::vector<std::vector<int>> pos(t);
	for (int i = 0; i < k; i++) {
		int a;
		std::cin >> a;
		a--;
		pos[a].push_back(i);
	}

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
	q.emplace(0, 0);
	std::vector<int> dis(n, -1);

	while (!q.empty()) {
		auto [d, x] = q.top();
		q.pop();

		if (dis[x] != -1) {
			continue;
		}
		dis[x] = d;

		for (auto [y, i] : adj[x]) {
			auto it = std::lower_bound(pos[i].begin(), pos[i].end(), d);
			if (it != pos[i].end()) {
				q.emplace(*it + 1, y);
			}
		}
	}

	std::cout << dis[n - 1] << "\n";

	return 0;
}