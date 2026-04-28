#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int U, V;
		std::cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
	}

	std::set<int> set;
	set.insert(0);

	std::vector<bool> vis(N);
	int cnt = 0;
	std::queue<int> q;


	auto bfs = [&](int k) {
		while (!q.empty()) {
			auto x = q.front();
			q.pop();
			for (int y : adj[x]) {
				if (!vis[y]) {
					if (y <= k) {
						vis[y] = true;
						cnt++;
						q.push(y);
					} else if (y > k) {
						set.insert(y);
					}
				}
			}
		}
	};
	
	
	for (int k = 0; k < N; k++) {
		if (!set.empty() && *set.begin() == k) {
			set.erase(k);
			q.push(k);
			vis[k] = true;
			cnt++;
			bfs(k);
			
			std::cout << (cnt == k + 1 ? (int)set.size() : -1) << "\n";
		} else {
			std::cout << "-1\n";
		}
	}
	

	return 0;
}