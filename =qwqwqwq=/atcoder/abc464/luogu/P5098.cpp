#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	int xmin = inf, xmax = -inf, ymin = inf, ymax = -inf;
	for (int i = 0; i < N; i++) {
		int x, y;
		std::cin >> x >> y;
		int nx = x + y, ny = x - y;
		xmin = std::min(xmin, nx);
		xmax = std::max(xmax, nx);
		ymin = std::min(ymin, ny);
		ymax = std::max(ymax, ny);
	}

	std::cout << std::max(xmax - xmin, ymax - ymin) << "\n";


	return 0;
}

