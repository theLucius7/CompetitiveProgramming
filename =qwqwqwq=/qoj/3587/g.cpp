#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, r, c;
	std::cin >> n >> m >> r >> c;
	r--, c--;

	std::vector<std::pair<int, int>> path;
	if (n % 2 == 0) {
		for (int x = 0; x < n; x++) {
			if (x % 2 == 0) {
				for (int y = m - 2; y >= 0; y--) {
					path.emplace_back(x, y);
				}
			} else {
				for (int y = 0; y < m - 1; y++) {
					path.emplace_back(x, y);
				}
			}
		}
		for (int x = n - 1; x >= 0; x--) {
			path.emplace_back(x, m - 1);
		}
	} else if (m % 2 == 0) {
		for (int y = 0; y < m; y++) {
			if (y % 2 == 0) {
				for (int x = 1; x < n; x++) {
					path.emplace_back(x, y);
				}
			} else {
				for (int x = n - 1; x >= 1; x--) {
					path.emplace_back(x, y);
				}
			}
		}
		for (int y = m - 1; y >= 0; y--) {
			path.emplace_back(0, y);
		}
	} else {
		for (int x = 0; x < n - 2; x++) {
			if (x % 2 == 0) {
				for (int y = m - 2; y >= 0; y--) {
					path.emplace_back(x, y);
				}
			} else {
				for (int y = 0; y < m - 1; y++) {
					path.emplace_back(x, y);
				}
			}
		}
		
		for (int y = 0; y < m - 1; y++) {
			if (y % 2 == 0) {
				for (int x = n - 2; x < n; x++) {
					path.emplace_back(x, y);
				}
			} else {
				for (int x = n - 1; x >= n - 2; x--) {
					path.emplace_back(x, y);
				}
			}
		}

		for (int x = n - 2; x >= 0; x--) {
			path.emplace_back(x, m - 1);
		}
	}



	std::vector nxt(n, std::vector<char>(m));
	for (int i = 0; i < path.size(); i++) {
		auto [x, y] = path[i];
		auto [nx, ny] = path[(i + 1) % path.size()];
		if (ny == y - 1) {
			nxt[x][y] = 'L';
		} else if (ny == y + 1) {
			nxt[x][y] = 'R';
		} else if (nx == x + 1) {
			nxt[x][y] = 'D';
		} else {
			nxt[x][y] = 'U';
		}
	}

	if (n % 2 == 1 && m % 2 == 1) {
		nxt[n - 1][m - 1] = 'U';
	}


	for (int _ = 0; _ < n * m - 1; _++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;

		if (n % 2 == 1 && m % 2 == 1) {
			if (x == n - 1 && y == m - 1) {
				nxt[n - 1][m - 2] = 'R';
			} else{
				nxt[n - 1][m - 2] = 'U';
			}
		}

		std::string ans = "";
		while (r != x || c != y) {
			char ne = nxt[r][c];
			ans.push_back(ne);
			if (ne == 'L') {
				c--;
			} else if (ne == 'R') {
				c++;
			} else if (ne == 'U') {
				r--;
			} else {
				r++;
			}
		}
		std::cout << ans << std::endl;
	}

	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}