#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::string> s(N);
	for (int i = 0; i < N; i++) {
		std::cin >> s[i];
	}

	std::vector<int> dx{1, 1, 1, -1, -1, -1, 0, 0}, dy{0, -1, 1, 0, -1, 1, -1, 1};
	std::vector<std::vector<bool>> vis(N, std::vector<bool> (M));
	auto dfs = [&](auto self, int x, int y) -> void {
		vis[x][y] = true;
		for (int i =  0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && s[nx][ny] == 'W' && !vis[nx][ny]) {
				self(self, nx, ny);
			}
		}
	};

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (s[i][j] == 'W' && !vis[i][j]) {
				dfs(dfs, i, j);
				cnt++;
			}
		}
	}
	std::cout << cnt << "\n";

	return 0;
}