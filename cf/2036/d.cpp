#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> g(n);
	for (int i = 0; i < n; i++) {
		std::cin >> g[i];
	}

	int ans = 0;
	auto calc = [&](int x, int y) {
		int nn = n - x, nm = m - y;
		std::string s;
		for (int i = y; i < nm; i++) {
			s.push_back(g[x][i]);
		}
		for (int i = x + 1; i < nn; i++) {
			s.push_back(g[i][nm - 1]);
		}
		for (int i = nm - 2; i >= y; i--) {
			s.push_back(g[nn - 1][i]);
		}
		for (int i = nn - 2; i >= x + 1; i--) {
			s.push_back(g[i][y]);
		}
		std::string t = s + s.substr(0, 3);

		// std::cout << t << ":(" << x << " " << y << ");\n";
		for (int i = 0; i + 3 < t.size(); i++) {
			if (t.substr(i, 4) == "1543") {
				ans++;
			}
		}
	};

	for (int i = 0; i < n / 2; i++) {
		if (i >= m / 2) {
			break;
		}
		calc(i, i);
	}

	std::cout << ans << "\n";
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
