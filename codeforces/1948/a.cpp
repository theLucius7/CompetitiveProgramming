#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

#define int long long

void solve() {
	int n;
	std::cin >> n;

	if (n % 2 == 1) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		std::vector<std::string> s{"AA", "BB"};
		int cur = 0;
		for (int i = 0; i < n / 2; i++) {
			std::cout << s[cur];
			cur = 1 - cur;
		}
		std::cout << "\n";
	}
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