#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W;
	std::cin >> H >> W;

	std::vector<std::string> s(H);
	for (int i = 0; i < H; i++) {
		std::cin >> s[i];
	}

	std::vector vis(H, std::vector<bool>(W));

	bool ok = true;
	int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
	auto dfs = [&](auto self, int x, int y) -> void {
		vis[x][y] = true;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
				if (s[nx][ny] == '.' && !vis[nx][ny]) {
					self(self, nx, ny);
				}
			} else {
				ok = false;
			}
		}
	};

	int ans = 0;
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			if (s[x][y] == '.' && !vis[x][y]) {
				ok = true;
				dfs(dfs, x, y);
				ans += ok;
			}
		}
	}

	std::cout << ans << "\n";

	return 0;
}