#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<std::tuple<int, int, int>> ranges(n);
	for (int i = 0; i < n; i++) {
		int l, r, real;
		std::cin >> l >> r >> real;
		ranges[i] = {l, r, real};
	}
	
	std::sort(ranges.begin(), ranges.end());

	for (int i = 0; i < n; i++) {
		auto [l, r, real] = ranges[i];
		if (k >= l && k <= r) {
			if (real >= k) {
				k = real;
			}
		}
	}
	std::cout << k << "\n";
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