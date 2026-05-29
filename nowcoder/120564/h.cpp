#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, q;
	std::cin >> n >> m >> q;

	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}

	i64 max = -1;
	std::pair<int, int> ans;

	std::vector<int> dx{-2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2};
	std::vector<int> dy{0, 1, 0, -1, 2, 1, 0, -1, -2, 1, 0, -1, 0};

	std::vector<std::vector<i64>> s(n, std::vector<i64>(m));

	auto calc = [&](int x, int y) {
		i64 sum = 0;
		for (int i = 0; i < 13; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				sum += a[nx][ny];
			}
		}
		s[x][y] = sum;
		if (sum > max) {
			max = sum;
			ans = {x, y};
		}
	};


	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			calc(x, y);
		}
	}

	auto update = [&](int x, int y, i64 z) {
		s[x][y] += z;
		if (s[x][y] > max) {
			max = s[x][y];
			ans = {x, y};
		}
	};

	while (q--) {
		int x, y;
		i64 z;
		std::cin >> x >> y >> z;
		x--, y--;
		a[x][y] += z;
		for (int i = 0; i < 13; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				update(nx, ny, z);
			}
		}

		std::cout << ans.first + 1 << " " << ans.second + 1 << "\n";
	}

	return 0;
}