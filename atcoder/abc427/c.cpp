#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair<int, int>> edges(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		edges[i] = {a, b};
	}

	int min = INT_MAX;
	for (int mask = 0; mask < (1 << n); mask++) {
		int cnt = 0;
		for (auto [x, y] : edges) {
			if (((mask >> x) & 1) == ((mask >> y) & 1)) {
				cnt++;
			}
		}
		min = std::min(min, cnt);
	}
	std::cout << min << "\n";


	return 0;
}