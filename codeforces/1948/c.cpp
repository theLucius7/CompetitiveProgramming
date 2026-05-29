#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

#define int long long

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::string> s(2);
	for (int i = 0; i < 2; i++) {
		std::cin >> s[i];
	}

	std::vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
	std::vector dis(2, std::vector<int>(n, -1));
	std::queue<std::pair<int, int>> q;
	q.push({0, 0});
	dis[0][0] = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < 2 && ny >= 0 && ny < n) {
				int nny = ny + (s[nx][ny] == '>' ? 1 : -1);
				if (nny >= 0 && nny < n && !~dis[nx][nny]) {
					q.push({nx, nny});
					dis[nx][nny] = dis[x][y] + 1;
				}
			}
		}
	}

	// for (int x = 0; x < 2; x++) {
	// 	for (int y = 0; y < n; y++) {
	// 		std::cout << dis[x][y] << " \n"[y == n - 1];
	// 	}
	// }

	std::cout << (~dis[1][n - 1] ? "YES" : "NO") << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}