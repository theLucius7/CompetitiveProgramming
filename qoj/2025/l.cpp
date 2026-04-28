#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());

	int ans = 1;

	// (l + 1) + (r + 1)  + 1 / 2 - 1
	// (l + r + 3) / 2 - 1
	// (l + r + 1) / 2
	for (int l = 0; l < n; l++) {
		for (int r = l + 1; r < n; r++) {
			if (a[l] + a[r] == 2 * a[(l + r) / 2]) {
				ans = std::max(ans, r - l + 1);
			}
		}
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