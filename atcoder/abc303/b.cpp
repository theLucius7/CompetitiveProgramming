#include <bits/stdc++.h>

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> g(M, std::vector<int>(N));
	std::vector<std::vector<bool>> vis(N + 1, std::vector<bool>(N + 1));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> g[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (j - 1 >= 0) {
				vis[g[i][j]][g[i][j - 1]] = 1;
			}
			if (j + 1 < N) {
				vis[g[i][j]][g[i][j + 1]] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j && vis[i][j] == 0) {
				cnt++;
			}
		}
	}

	std::cout << cnt / 2 << "\n";

	return 0;
}