#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> b(m);
	std::vector<int> cnt(n + m + 1);
	std::vector<int> sum(n + m + 1);
	int maxa = 0, maxb = 0;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		cnt[a]++;
		maxa = std::max(maxa, a);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
		maxb = std::max(maxb, b[i]);
	}

	for (int x = 1; x <= maxa; x++) {
		if (cnt[x] == 0) {
			continue;
		}
		for (int y = x; y <= maxb; y += x) {
			sum[y] += cnt[x];
		}
	}


	int A = 0, B = 0, AB = 0;
	for (int i = 0; i < m; i++) {
		if (sum[b[i]] && n - sum[b[i]]) {
			AB++;
		} else if (sum[b[i]]) {
			A++;
		} else if (n - sum[b[i]]) {
			B++;
		}
	}

	std::cout << (A + (AB % 2) > B ? "Alice" : "Bob") << "\n";

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