#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	std::vector<int> cnt(2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt[s[i][j] - '0']++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cnt[s[i][j] - '0'] >= 2) {
				std::cout << "Y";
			} else {
				std::cout << "N";
			}

			if (j == m - 1) {
				std::cout << "\n";
			}
		}
	}

	
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