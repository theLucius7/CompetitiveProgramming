#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	i64 ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		std::cin >> u >> v;

		i64 w;
		std::cin >> w;
		ans += w;
	}

	std::cout << 2 * ans << "\n";

	return 0;
}