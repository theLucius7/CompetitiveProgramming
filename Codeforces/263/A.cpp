#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector g(5, std::vector<int>(5));
	int x, y;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> g[i][j];
			if (g[i][j]) {
				x = i;
				y = j;
			}
		}
	}

	std::cout << std::abs(x - 2) + std::abs(y - 2) << "\n";

	return 0;
}