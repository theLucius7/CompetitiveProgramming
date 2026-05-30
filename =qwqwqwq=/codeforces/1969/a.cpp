#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

#define int long long

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n);
	bool f = false;
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
		p[i]--;
	}

	for (int i = 0; i < n; i++) {
		if (p[p[i]] == i) {
			std::cout << 2 << "\n";
			return;
		}
	}
	std::cout << 3 << "\n";

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}