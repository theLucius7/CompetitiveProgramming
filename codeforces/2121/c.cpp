#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
			max = std::max(max, a[i][j]);
		}
	}

	std::vector<int> cnti(n), cntj(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == max) {
				cnti[i]++;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i][j] == max) {
				cntj[j]++;
			}
		}
	}

	int cnt = std::accumulate(cnti.begin(), cnti.end(), 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cnti[i] + cntj[j] + (a[i][j] == max ? -1 : 0) == cnt) {
				std::cout << max - 1 << "\n";
				return;
			}
		}
	}
	std::cout << max << "\n";
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