#include <bits/stdc++.h>

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W;
	std::cin >> H >> W;

	std::map<char, char> mp;
	mp['s'] = 'n', mp['n'] = 'u', mp['u'] = 'k', mp['k'] = 'e', mp['e'] = 's';

	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}

	std::vector<std::vector<bool>> vis(H, std::vector<bool> (W));

	std::queue<std::pair<int, int>> q;
	q.push({0, 0});
	vis[0][0] = true;
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (x == H - 1 && y == W - 1) {
			std::cout << "Yes\n";
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < H && ny >= 0 && ny < W && S[nx][ny] == mp[S[x][y]] && !vis[nx][ny]) {
				q.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
	}

	std::cout << "No\n";

	return 0;
}