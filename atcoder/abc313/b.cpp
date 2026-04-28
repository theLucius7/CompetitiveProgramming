#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<bool>> g(N, std::vector<bool> (N));
	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		a--, b--;

		g[a][b] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (g[j][i] && g[i][k]) {
					g[j][k] = true;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		bool ok = true;
		for (int j = 0; j < N; j++) {
			if (i != j && g[i][j] == false) {
				ok = false;
				break;
			}
		}

		if (ok) {
			std::cout << i + 1 << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";

	return 0;
}