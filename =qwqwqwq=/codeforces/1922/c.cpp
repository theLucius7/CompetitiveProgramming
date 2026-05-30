#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			r[i] = 1;
		} else if (i == n - 1) {
			l[i] = 1;
		} else {
			if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
				l[i] = 1;
				r[i] = a[i + 1] - a[i];
			} else {
				r[i] = 1;
				l[i] = a[i] - a[i - 1];
			}
		}
	}

	std::vector<int> pre(n + 1), suf(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + r[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		suf[i] = suf[i + 1] + l[i];
	}


	int m;
	std::cin >> m;

	while (m--) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		std::cout << (x < y ? pre[y] - pre[x] : suf[y + 1] - suf[x + 1]) << "\n";
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