#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector g(N, std::vector<int>(N));

	int r = 0, c = (N - 1) / 2;
	g[r][c] = 1;
	for (int t = 0; t < N * N - 1; t++) {
		if (!g[(r - 1 + N) % N][(c + 1) % N]) {
			r = (r - 1 + N) % N, c = (c + 1) % N;
			g[r][c] = t + 2;
		} else {
			r = (r + 1) % N;
			g[r][c] = t + 2;
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			std::cout << g[x][y] << " \n"[y == N - 1];
		}
	}


	return 0;
}

