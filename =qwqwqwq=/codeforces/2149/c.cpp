#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> cnt(n + 1);
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		cnt[a]++;
	}

	int x = 0, y = 0;
	for (int i = 0; i <= k; i++) {
		if (i < k) {
			x += cnt[i] == 0;
		} else {
			y += cnt[i];
		}
	}
	std::cout << std::max(x, y) << "\n";
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