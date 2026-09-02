#include <bits/stdc++.h>


void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> o(n), ans(n);
	std::iota(o.begin(), o.end(), 0);
	std::sort(o.begin(), o.end(), [&](int i, int j) {
		return a[i] < a[j];
	});

	std::sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		ans[o[i]] = b[i];
	}
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1];
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