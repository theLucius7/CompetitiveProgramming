#include <bits/stdc++.h>

constexpr int inf = 1E9;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> q(n);
	for (int i = 0; i < n; i++) {
		std::cin >> q[i];
	}

	int m;
	std::cin >> m;

	std::vector<int> f(n, inf);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		a--, b--;
		if (q[a] > q[b]) {
			f[b] = std::min(f[b], c);
		}
	}

	if (std::count(f.begin(), f.end(), inf) > 1) {
		std::cout << "-1\n";
		return 0;
	}

	auto ans = std::accumulate(f.begin(), f.end(), 0) - inf;
	std::cout << ans << "\n";

	return 0;
}