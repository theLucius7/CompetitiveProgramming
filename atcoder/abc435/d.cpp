#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int X, Y;
		std::cin >> X >> Y;
		X--, Y--;
		adj[Y].push_back(X);
	}

	int Q;
	std::cin >> Q;

	std::vector<bool> vis(N);
	auto dfs = [&](auto self, int x) -> void {
		vis[x] = true;
		for (int y : adj[x]) {
			if (!vis[y]) {
				self(self, y);
			}
		}
	};


	for (int i = 0; i < Q; i++) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int v;
			std::cin >> v;
			v--;
			if (!vis[v]) {
				dfs(dfs, v);
			}
		} else {
			int v;
			std::cin >> v;
			v--;
			std::cout << (vis[v] ? "Yes" : "No") << "\n";
		}
	}


	return 0;
}