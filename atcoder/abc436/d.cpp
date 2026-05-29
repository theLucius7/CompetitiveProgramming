#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W;
	std::cin >> H >> W;

	std::vector<std::string> g(H);
	for (int i = 0; i < H; i++) {
		std::cin >> g[i];
	}

	std::map<char, std::vector<std::pair<int, int>>> map;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (g[i][j] >= 'a' && g[i][j] <= 'z') {
				map[g[i][j]].push_back({i, j});
			}
		}
	}

	// for (auto [c, v] : map) {
	// 	std::cout << c << ": ";
	// 	for (auto [x, y] : v) {
	// 		std::cout << "{" << x << "," << y << "}" << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	std::queue<std::array<int, 3>> q;
	std::vector vis(H, std::vector<bool>(W));
	int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
	q.push({0, 0, 0});
	vis[0][0] = true;

	while (!q.empty()) {
		auto [cnt, x, y] = q.front();
		q.pop();

		if (cnt >= H * W) {
			std::cout << "-1\n";
			return 0;
		}

		if (x == H - 1 && y == W - 1) {
			std::cout << cnt << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && g[nx][ny] != '#') {
				q.push({cnt + 1, nx, ny});
				vis[nx][ny] = true;	
			}
		}

		for (auto [nx, ny] : map[g[x][y]]) {
			if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
				q.push({cnt + 1, nx, ny});
				vis[nx][ny] = true;
			}
			map[g[x][y]].clear();
		}
	}

	std::cout << "-1\n";


	return 0;
}

