#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 mod = k + 1;
	for (int i = 0; i < n; i++) {
		i64 x = a[i] % mod;
		a[i] += x * k;
	}

	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " \n"[i == n - 1];
	}
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}