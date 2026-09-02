#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;

	int xy = 0;
	std::vector<int> deg(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		deg[u]++;
		deg[v]++;
	}
	xy = std::count(deg.begin(), deg.end(), 1);
	int x = n - 1 - xy, y = xy / x;
	std::cout << x << " " << y << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}