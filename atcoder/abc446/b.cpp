#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<bool> vis(M + 1);

	for (int i = 0; i < N; i++) {
		int L;
		std::cin >> L;

		bool ok = false;
		for (int j = 0; j < L; j++) {
			int X;
			std::cin >> X;
			if (!vis[X] && !ok) {
				ok = true;
				vis[X] = true;
				std::cout << X << "\n";
				// break;
			}
		}

		if (!ok) {
			std::cout << 0 << "\n";
		}
	}

	return 0;
}