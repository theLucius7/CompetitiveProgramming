#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector A(N, std::vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			std::cin >> A[i][j];
			A[j][i] = A[i][j];
		}
	}

	std::vector<std::vector<std::pair<int, int>>> adj(N);
	std::vector<bool> vis(N);
	vis[0] = true;

	auto f = A[0];
	for (int _ = 1; _ < N; _++) {
		int x = -1;
		for (int i = 0; i < N; i++) {
			if (!vis[i] && (x == -1 || f[i] < f[x])) {
				x = i;
			}
		}

		for (int i = 0; i < N; i++) {
			if (vis[i] && f[x] == A[x][i]) {
				adj[i].push_back({x, f[x]});
				adj[x].push_back({i, f[x]});
				break;
			}
		}

		vis[x] = true;

		for (int i = 0; i < N; i++) {
			f[i] = std::min(f[i], A[x][i]);
		}
	}

	for (int i = 0; i < N; i++) {
		std::vector<int> d(N);
		[&](this auto &&self, int x, int p) -> void {
			for (auto [y, w] : adj[x]) {
				if (y == p) {
					continue;
				}
				d[y] = d[x] + w;
				self(y, x);
			}
		}(i, -1);

		if (d != A[i]) {
			std::cout << "No\n";
			return 0;
		}
	}

	std::cout << "Yes\n";


	return 0;
}