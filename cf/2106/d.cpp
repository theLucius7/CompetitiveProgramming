#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 1;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::vector<int> pre(n + 1), suf(n + 1);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur < m && a[i] >= b[cur]) {
			cur++;
		}
		pre[i + 1] = cur;
	}
	cur = m - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (cur >= 0 && a[i] >= b[cur]) {
			cur--;
		}
		suf[i] = m - 1 - cur;
	}

	// for (int i = 0; i < n; i++) {
	// 	// std::cout << pre[i] << " \n"[i == n - 1];
	// }
	// for (int i = 0; i < n; i++) {
	// 	// std::cout << suf[i] << " \n"[i == n - 1];
	// }

	int min = inf;
	for (int i = 0; i <= n; i++) {
		if (pre[i] + suf[i] == m) {
			std::cout << 0 << "\n";
			return;
		} else if (pre[i] + suf[i] == m - 1) {
			min = std::min(min, b[pre[i]]);
		}
	}
	std::cout << (min == inf ? -1 : min) << "\n";

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