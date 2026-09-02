#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::array<int, 3>> p(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> p[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		int mina = std::min(p[0][i], p[1][i]), maxa = std::max(p[0][i], p[1][i]);
		int minb = std::min(p[2][i], p[3][i]), maxb = std::max(p[2][i], p[3][i]);
		if (mina >= maxb || minb >= maxa) {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";

	return 0;
}