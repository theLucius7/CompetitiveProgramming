#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		if (i & 1) {
			if (i == n - 1) {
				std::cout << 2;
			} else {
				std::cout << 3;
			}
		} else {
			std::cout << -1;
		}
		std::cout << " \n"[i == n - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}


	return 0;
}