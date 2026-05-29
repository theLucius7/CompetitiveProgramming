#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int M, N;
	std::cin >> M >> N;

	std::vector<std::string> g(M);
	for (int i = 0; i < M; i++) {
		std::cin >> g[i];
	}

	if (g[0][0] == '#') {
		std::cout << "-1\n";
		return 0;
	}

	constexpr int inf = 1E9;

	std::vector mn(M, std::vector<std::array<int, 2>>(N, {inf, inf})), mx(M, std::vector<std::array<int, 2>>(N, {-inf, -inf}));
	mn[0][0] = {0, 0}, mx[0][0] = {0, 0};
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (g[i][j] == '#') {
				continue;
			}

			if (i == 0 && j == 1) {
				mn[i][j][0] = mn[i][j - 1][0];
				mx[i][j][0] = mx[i][j - 1][0];
				continue;
			}

			if (i == 1 && j == 0) {
				mn[i][j][1] = mn[i - 1][j][1];
				mx[i][j][1] = mx[i - 1][j][1];
				continue;
			}

			if (i > 0 && g[i - 1][j] != '#') {
				if (mn[i - 1][j][0] != inf) {
					mn[i][j][1] = std::min(mn[i][j][1], mn[i - 1][j][0] + 1);
					mx[i][j][1] = std::max(mx[i][j][1], mx[i - 1][j][0] + 1);
				}
				if (mn[i - 1][j][1] != inf) {
					mn[i][j][1] = std::min(mn[i][j][1], mn[i - 1][j][1]);
					mx[i][j][1] = std::max(mx[i][j][1], mx[i - 1][j][1]);
				}
			}
			if (j > 0 && g[i][j - 1] != '#') {
				if (mn[i][j - 1][0] != inf) {
					mn[i][j][0] = std::min(mn[i][j][0], mn[i][j - 1][0]);
					mx[i][j][0] = std::max(mx[i][j][0], mx[i][j - 1][0]);
				}
				if (mn[i][j - 1][1] != inf) {
					mn[i][j][0] = std::min(mn[i][j][0], mn[i][j - 1][1] + 1);
					mx[i][j][0] = std::max(mx[i][j][0], mx[i][j - 1][1] + 1);
				}
			}
		}
	}

	int min = std::min(mn[M - 1][N - 1][0], mn[M - 1][N - 1][1]), max = std::max(mx[M - 1][N - 1][0], mx[M - 1][N - 1][1]);
	if (min == inf) {
		std::cout << "-1\n";
	} else {
		std::cout << max << " " << min << "\n";
	}

	return 0;
}