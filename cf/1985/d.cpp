#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	int h1 = -1, h2 = -1;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') {
				flag = true;
			}
		}

		if (flag && h1 == -1) {
			h1 = i;
		}
		if (!flag && h1 != -1 && h2 == -1) {
			h2 = i;
		}
	}

	int k1 = -1, k2 = -1;
	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (s[j][i] == '#') {
				flag = true;
			}
		}

		if (flag && k1 == -1) {
			k1 = i;
		}
		if (!flag && k1 != -1 && k2 == -1) {
			k2 = i;
		}
	}

	if (h2 == -1) {
		h2 = n;
	}
	if (k2 == -1) {
		k2 = m;
	}

	int h = (h2 + h1 + 1) / 2, k = (k2 + k1 + 1) / 2;
	std::cout << h << " " << k << "\n";
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
