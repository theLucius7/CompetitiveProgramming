#include <bits/stdc++.h>

#define int long long

using i64 = long long;

void solve() {
	std::vector<int> a(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());

	std::cout << (a[0] + a[1] == a[2] ? "YES" : "NO") << "\n";

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}