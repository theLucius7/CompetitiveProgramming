#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
	}

	std::queue<int> q;
	std::vector<bool> vis(N);
	q.push(0);
	vis[0] = true;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		for (int y : adj[x]) {
			if (!vis[y]) {
				vis[y] = true;
				q.push(y);
			}
		}
	}

	std::cout << std::count(vis.begin(), vis.end(), true) << "\n";

	return 0;
}