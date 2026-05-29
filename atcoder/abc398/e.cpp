#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long


signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> adj(N);
	std::vector<std::vector<bool>> g(N, std::vector<bool>(N));
	for (int i = 0; i < N - 1; i++) {
		int U, V;
		std::cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
		g[U][V] = g[V][U] = true;
	}

	std::vector<int> f(N, -1);
	std::queue<int> q;
	f[0] = 0;
	q.push(0);
	while (!q.empty()) {
		auto x = q.front();
		q.pop();

		for (int y : adj[x]) {
			if (f[y] == -1) {
				f[y] = f[x] ^ 1;
				q.push(y); 
			}
		}
	}

	int cnt0 = std::count(f.begin(), f.end(), 0), cnt1 = std::count(f.begin(), f.end(), 1);

	int cur = 0;
	if ((cnt0 * cnt1 - (N - 1)) % 2 == 1) {
		std::cout << "First" << std::endl;
	} else {
		std::cout << "Second" << std::endl;
		cur = 1;
	}

	int x = 1, y = 0;
	while (true) {
		if (cur == 1) {
			int U, V;
			std::cin >> U >> V;
			if (U == -1) {
				break;
			}
			U--, V--;
			g[U][V] = g[V][U] = true;
			cur ^= 1;
		} else {
			while (g[x][y] || f[x] == f[y]) {
				y++;
				if (y == x) {
					x++;
					y = 0;
				}
			}
			g[x][y] = g[y][x] = true;
			cur ^= 1;
			std::cout << y + 1 << " " << x + 1 << std::endl;
		}
	}

	return 0;
}