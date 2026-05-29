#include <bits/stdc++.h>

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}

	int ans = 0;
	std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && a[i][j] != 0) {
				int res = 0;
				std::queue<std::pair<int, int>> q;
				q.emplace(i, j);
				while(!q.empty()) {
					auto [x, y] = q.front();
					q.pop();
					vis[x][y] = true;
					res += a[x][y];

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] && a[nx][ny] != 0) {
							q.emplace(nx, ny);
							vis[nx][ny] = true;
						}
					}
				}
				ans = std::max(ans, res);
			}
		}
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}