#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	i64 cur = 1;
	std::vector<std::vector<int>> g(n, std::vector<int>(n));

	auto dfs = [&](auto self, int x1, int y1, int x2, int y2) {

	};
	dfs(dfs, 1, 1, std::pow(2, n), std::pow(2, n));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}