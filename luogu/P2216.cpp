#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 1;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b, n;
	std::cin >> a >> b >> n;

	std::vector<std::vector<int>> g(a, std::vector<int>(b));
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			std::cin >> g[i][j];
		}
	}

	std::vector<std::vector<int>> rowMin(a, std::vector<int>(b - n + 1)), rowMax(a, std::vector<int>(b - n + 1));
	for (int x = 0; x < a; x++) {
		std::deque<int> qMin, qMax;
		for (int y = 0; y < b; y++) {
			while (!qMin.empty() && g[x][y] <= g[x][qMin.back()]) {
				qMin.pop_back();
			}
			qMin.push_back(y);
			if (y - qMin.front() > n - 1) {
				qMin.pop_front();
			}
			if (y >= n - 1) {
				rowMin[x][y - n + 1] = g[x][qMin.front()];
			}
		}

		for (int y = 0; y < b; y++) {
			while (!qMax.empty() && g[x][y] >= g[x][qMax.back()]) {
				qMax.pop_back();
			}
			qMax.push_back(y);
			if (y - qMax.front() > n - 1) {
				qMax.pop_front();
			}
			if (y >= n - 1) {
				rowMax[x][y - n + 1] = g[x][qMax.front()];
			}
		}
	}

	std::vector<std::vector<int>> min(a - n + 1, std::vector<int>(b - n + 1)), max(a - n + 1, std::vector<int>(b - n + 1));
	for (int y = 0; y < b - n + 1; y++) {
		std::deque<int> qMin, qMax;
		for (int x = 0; x < a; x++) {
			while (!qMin.empty() && rowMin[x][y] <= rowMin[qMin.back()][y]) {
				qMin.pop_back();
			}
			qMin.push_back(x);
			if (x - qMin.front() > n - 1) {
				qMin.pop_front();
			}
			if (x >= n - 1) {
				min[x - n + 1][y] = rowMin[qMin.front()][y];
			}
		}
		for (int x = 0; x < a; x++) {
			while (!qMax.empty() && rowMax[x][y] >= rowMax[qMax.back()][y]) {
				qMax.pop_back();
			}
			qMax.push_back(x);
			if (x - qMax.front() > n - 1) {
				qMax.pop_front();
			}
			if (x >= n - 1) {
				max[x - n + 1][y] = rowMax[qMax.front()][y];
			}
		}
	}


	// for (int x = 0; x < a - n + 1; x++) {
	// 	for (int y = 0; y < b - n + 1; y++) {
	// 		std::cout << max[x][y] << " \n"[y == b - n];
	// 	}
	// }
	// std::cout << "\n";

	// for (int x = 0; x < a - n + 1; x++) {
	// 	for (int y = 0; y < b - n + 1; y++) {
	// 		std::cout << min[x][y] << " \n"[y == b - n];
	// 	}
	// }

	int ans = inf;
	for (int x = 0; x < a - n + 1; x++) {
		for (int y = 0; y < b - n + 1; y++) {
			ans = std::min(ans, max[x][y] - min[x][y]);
		}
	}
	std::cout << ans << "\n";


	return 0;
}