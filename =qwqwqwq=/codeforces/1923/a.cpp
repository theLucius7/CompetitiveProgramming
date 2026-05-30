#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	int l = inf, r = -inf;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];

		if (a[i]) {
			l = std::min(l, i);
			r = std::max(r, i);
		}
	}

	// std::cout << l << " " << r << "\n";

	int cnt = 0;
	for (int i = l; i <= r; i++) {
		cnt += a[i] == 0;
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