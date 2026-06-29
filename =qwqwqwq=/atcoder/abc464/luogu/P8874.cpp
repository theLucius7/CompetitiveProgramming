#include <bits/stdc++.h>

#define int long long

using i64 = long long;

struct Cell {
	int owner = -1;
	int level = 0;
	int cost = 0;
};

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, q, L;
	std::cin >> n >> m >> q >> L;

	std::vector<std::vector<int>> C(n, std::vector<int>(L));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < L; j++) {
			std::cin >> C[i][j];
		}
	}

	std::vector<int> d(n);
	for (int i = 0; i < n; i++) {
		std::cin >> d[i];
	}

	int u = 1;
	std::vector<int> X(2), sum(2, m);
	std::vector<Cell> c(n);
	int op, k;
	std::vector<int> income(2);
	for (int t = 0; t < 2 * q; t++) {
		std::cin >> op >> k;

		u ^= 1;
		for (int i = 1; i <= k; i++) {
			X[u] += 1;
			X[u] %= n;
			if (c[X[u]].owner == (u ^ 1)) {
				sum[u] -= c[X[u]].cost;
				sum[u ^ 1] += c[X[u]].cost;
				if (sum[u] < 0) {
					std::cout << (u == 0 ? "Renko" : "Merry") << "\n";
					return 0;
				}
			} else if (c[X[u]].owner == u) {
				sum[u] += c[X[u]].cost;
			}
		}

		while (isspace(std::cin.peek())) {
			std::cin.get();
		}
		op = std::cin.peek();

		if (op == '2') {
			std::cin >> op >> k;

			if (c[X[u]].owner == -1 || c[X[u]].owner == u) {
				int aim = std::min(c[X[u]].level + k, L);;
				for (int i = c[X[u]].level; i < aim; i++) {
					if (C[X[u]][i] <= sum[u]) {
						sum[u] -= C[X[u]][i];
						c[X[u]].cost += C[X[u]][i];
						c[X[u]].level++;

						if (c[X[u]].owner == -1) {
							c[X[u]].owner = u;	
							income[u] += d[X[u]];
						}
					} else {
						break;
					}
				}
			}	
		}

		if (t % 2 == 1) {
			sum[0] += income[0];
			sum[1] += income[1];
		}
	}

	std::cout << sum[0] << " " << sum[1] << "\n";

	return 0;
}