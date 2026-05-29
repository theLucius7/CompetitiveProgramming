#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, x;
	std::cin >> n >> x;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end(), std::greater<int>());

	int cnt = 0;
	for (int l = 0; l < n; ) {
		int r = l + 1;
		while (r < n && (r - l) * a[r - 1] < x) {
			r++;
		}
		if ((r - l) * a[r - 1] >= x) {
			cnt++;
		}
		l = r;
	}
	std::cout << cnt << "\n";
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