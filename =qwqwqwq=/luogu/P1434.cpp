#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int R, C;
	std::cin >> R >> C;

	std::vector<std::vector<int>> a(R, std::vector<int>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> a[i][j];
		}
	}

	std::vector<int> dx{1, -1, 0, 0}, dy{0, 0, -1, 1};

	std::vector<std::vector<int>> dis(R, std::vector<int>(C, -1));
	auto dfs = [&](auto self, int x, int y) -> int {
		dis[x][y] = 1;

		int max = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && a[x][y] > a[nx][ny]) {
				if (dis[nx][ny] != -1) {
					max = std::max(max, dis[nx][ny]);
				} else {
					max = std::max(max, self(self, nx, ny));
				}
			}
		}
		dis[x][y] += max;
		return dis[x][y];
	};


	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (dis[i][j] != -1) {
				ans = std::max(ans, dis[i][j]);
			} else {
				ans = std::max(ans, dfs(dfs, i, j));
			}
		}
	}
	std::cout << ans << "\n";


	return 0;
}