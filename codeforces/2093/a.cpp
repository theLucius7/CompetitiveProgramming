#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int k;
	std::cin >> k;

	if (k % 2 == 0) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
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