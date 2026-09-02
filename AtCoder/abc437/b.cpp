#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W, N;
	std::cin >> H >> W >> N;

	std::vector g(H, std::vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> g[i][j];
		}
	}

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	int max = 0;
	for (int i = 0; i < H; i++) {
		int cnt = 0;
		for (int j = 0; j < W; j++) {
			for (int x = 0; x < N; x++) {
				if (A[x] == g[i][j]) {
					cnt++;
				}
			}
		}
		max = std::max(max, cnt);
		// std::cout << cnt << " \n"[i == H - 1];
	}
	std::cout << max << "\n";

	return 0;
}