#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i < 4; i++) {
		if (a[i] != a[0]) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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