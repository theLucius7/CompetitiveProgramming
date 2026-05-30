#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 sum = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		odd += a[i] % 2;

		if (i == 0) {
			std::cout << a[i] << " \n"[i == n - 1];
		} else {
			std::cout << sum - odd / 3 - (odd % 3 == 1) << " \n"[i == n - 1];
		}
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