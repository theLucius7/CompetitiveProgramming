#include <bits/stdc++.h>

using i64 = long long;

int pre[1010][1010][5];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W;
	std::cin >> H >> W;

	std::vector<std::string> g(H);
	std::pair<int, int> S;
	for (int i = 0; i < H; i++) {
		std::cin >> g[i];
		for (int j = 0; j < W; j++) {
			if (g[i][j] == 'S') {
				S = {i, j};
			} 
		}
	}

	int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
	// std::vector<std::vector<std::array<int, 5>>> pre(H, std::vector<std::array<int, 4>>(W));
	std::queue<std::array<int, 3>> q;
	
	pre[S.first][S.second][0] = -1;
	pre[S.first][S.second][1] = -1;
	pre[S.first][S.second][2] = -1;
	pre[S.first][S.second][3] = -1;
	q.push({S.first, S.second, 0});
	q.push({S.first, S.second, 1});
	q.push({S.first, S.second, 2});
	q.push({S.first, S.second, 3});
	while (!q.empty()) {
		auto [x, y, dir] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
				if (g[x][y] == 'o') {
					if (i != dir) {
						continue;
					}
				} else if (g[x][y] == 'x') {
					if (i == dir) {
						continue;
					}
				}

				if (g[nx][ny] == '.') {
					if (!pre[nx][ny][i]) {
						q.push({nx, ny, i});
						pre[nx][ny][i] = dir + 1;
					}
				} else if (g[nx][ny] == 'o' || g[nx][ny] == 'x') {
					if (!pre[nx][ny][i]) {
						q.push({nx, ny, i});
						pre[nx][ny][i] = dir + 1;
					}
				} else if (g[nx][ny] == 'G') {
					pre[nx][ny][i] = dir + 1;
					std::string ans;
					int op = i + 1;
					int nnx = nx, nny = ny;
					while (op != -1) {
						if (op == 1) {
							ans.push_back('R');
						} else if (op == 2) {
							ans.push_back('L');
						} else if (op == 3) {
							ans.push_back('D');
						} else {
							ans.push_back('U');
						}
						int nop = pre[nnx][nny][op - 1];
						nnx -= dx[op - 1];
						nny -= dy[op - 1];

						if (nnx == S.first && nny == S.second) {
							break;
						}
						op = nop;
					}
					std::reverse(ans.begin(), ans.end());
					std::cout << "Yes\n";
					std::cout << ans << "\n";
					return 0;
				}
			}
		}
	}

	std::cout << "No\n";
	



	return 0;
}	