#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	if (k % 2 == 1) {
		for (int i = 0; i < k; i++) {
			std::cout << n << " \n"[i == k - 1];
		}
	} else {
		for (int i = 0; i < k - 1; i++) {
			std::cout << n << " ";
		}
		std::cout << 0 << "\n";
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