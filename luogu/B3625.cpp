#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	std::vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
	std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
	auto dfs = [&](auto self, int x, int y) -> void {
		vis[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] == '.' && !vis[nx][ny]) {
				self(self, nx, ny);
			}
		}
	};

	if (s[0][0] == '.') {
		dfs(dfs, 0, 0);
	}

	std::cout << (vis[n - 1][m - 1] ? "Yes" : "No") << "\n";



	return 0;
}