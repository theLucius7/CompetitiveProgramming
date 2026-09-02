#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int M, A, B;
	std::cin >> M >> A >> B;

	std::vector<std::vector<int>> adj(M * M);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			int k = (A * j + B * i) % M;
			adj[j * M + k].push_back(i * M + j);
		}
	}

	std::queue<int> q;
	for (int i = 0; i < M; i++) {
		q.push(i * M);
		if (i) {
			q.push(i);
		}
	}

	std::vector<bool> vis(M * M);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		vis[x] = true;

		for (int y : adj[x]) {
			if (!vis[y]) {
				q.push(y);
			}
		}
	}


	std::cout << std::count(vis.begin(), vis.end(), false) << "\n";
	

	return 0;
}