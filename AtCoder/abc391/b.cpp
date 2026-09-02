#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int P = 998244353;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;


	std::vector<std::string> S(N), T(M);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	for (int i = 0; i < M; i++) {
		std::cin >> T[i];
	}

	for (int i = 0; i + M - 1 < N; i++) {
		for (int j = 0; j + M - 1 < N; j++) {
			bool ok = true;
			for (int dx = 0; dx < M; dx++) {
				for (int dy = 0; dy < M; dy++) {
					if (S[i + dx][j + dy] != T[dx][dy]) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					break;
				}
			}

			if (ok) {
				std::cout << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
		}
	}

	return 0;
}