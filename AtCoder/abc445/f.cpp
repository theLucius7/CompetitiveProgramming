#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

std::vector<std::vector<i64>> operator*(std::vector<std::vector<i64>> &a, std::vector<std::vector<i64>> &b) {
	int n = a.size();
	std::vector c(n, std::vector<i64>(n, inf));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][k] = std::min(c[i][k], a[i][j] + b[j][k]);
			}
		}
	}
	return c;
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector C(N, std::vector<i64>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> C[i][j];
		}
	}

	std::vector ans(N, std::vector<i64>(N, inf));
	for (int i = 0; i < N; i++) {
		ans[i][i] = 0;
	}

	for ( ; K; K /= 2, C = C * C) {
		if (K & 1) {
			ans = ans * C;
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << ans[i][i] << "\n";
	}
	

	return 0;
}

