#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 1;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> min(n), max(n);
	min[0] = a[0];
	for (int i = 1; i < n; i++) {
		min[i] = std::min(min[i - 1], a[i]);
	}
	max[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		max[i] = std::max(max[i + 1], a[i]);
	}

	// for (int i = 0; i < n; i++) {
	// 	std::cout << max[i] << " \n"[i == n - 1];
	// }

	for (int i = 0; i < n; i++) {
		std::cout << ((a[i] == max[i] || a[i] == min[i]) ? "1" : "0");
	}

	std::cout << "\n";
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