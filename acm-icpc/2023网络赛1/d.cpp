#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::vector<bool> vis(n);
	i64 ans = 0;
	std::vector<int> sizes;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			std::queue<int> q;
			q.push(i);
			vis[i] = true;

			i64 edges = 0, sz = 0;
			while (q.size()) {
				int t = q.front();
				q.pop();

				edges += adj[t].size();
				sz++;

				for (auto v : adj[t]) {
					if (!vis[v]) {
						q.push(v);
						vis[v] = true;
					}
				}
			}
			edges /= 2;
			ans += sz * (sz - 1) / 2 - edges;

			sizes.push_back(sz);
		}
	}

	if (ans > 0) {
		std::cout << ans << "\n";
	} else {
		std::sort(sizes.begin(), sizes.end());
		std::cout << 1LL * sizes[0] * sizes[1] << "\n";
	}

	return 0;
}