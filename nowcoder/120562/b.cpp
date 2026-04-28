#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int max = *std::max_element(a.begin(), a.end());
	if (std::count(a.begin(), a.end(), max) % 2) {
		for (int i = 0; i < n; i++) {
			if (a[i] == max) {
				std::cout << 1;
			} else {
				std::cout << 0;
			}
		}
		std::cout << "\n";
	} else {
		for (int i = 0; i < n; i++) {
			if (a[i] != max) {
				std::cout << 1;
			} else {
				std::cout << 0;
			}
		}
		std::cout << "\n";
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