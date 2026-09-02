#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> b(n);
	i64 product = 1;
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
		product *= b[i];
	}

	if (2023 % product == 0) {
		std::cout << "YES\n";
		for (int i = 0; i < k; i++) {
			if (i == 0) {
				std::cout << 2023 / product;
			} else {
				std::cout << "1";
			}
			std::cout << " \n"[i == k - 1];
		}
	} else {
		std::cout << "NO\n";
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