#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<int> up(N, -1), down(N, -1);
	for (int i = 0; i < Q; i++) {
		int C, P;
		std::cin >> C >> P;
		C--, P--;
		if (down[C] != -1) {
			up[down[C]] = -1;
		}

		down[C] = P;
		up[P] = C;
	}

	for (int i = 0; i < N; i++) {
		if (down[i] != -1) {
			std::cout << 0;
		} else {
			int cnt = 0;
			for (int now = i; now != -1; now = up[now], cnt++);
			std::cout << cnt;
		}
		std::cout << " \n"[i == N - 1];
	}
	

	return 0;
}
