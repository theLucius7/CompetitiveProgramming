#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
	i64 n;
	int m;
	std::cin >> n >> m;

	std::vector<i64> a(m);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		if (i > 0) {
			if (a[i] != a[i - 1] + 1) {
				std::cout << 1 << "\n";
				return;
			}
		}
	}

	std::cout << n - a[m - 1] + 1 << "\n";

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