#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

void solve() {
	int n, m;
	std::cin >> n >> m;


	std::vector g(n, std::vector<int> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> g[i][j];
		}
	}

	int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			bool ok = true;
			int max = 0;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (g[x][y] <= g[nx][ny]) {
						ok = false;
						break;
					}
					max = std::max(max, g[nx][ny]);
				}
			}
			if (ok) {
				g[x][y] = max;
			}
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			std::cout << g[x][y] << " \n"[y == m - 1];
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