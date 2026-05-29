#include <bits/stdc++.h>

using i64 = long long;

i64 primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 gcd = a[0];
	for (int i = 1; i < n; i++) {
		gcd = std::gcd(gcd, a[i] - a[i - 1]);
	}

	for (i64 p : primes) {
		if (gcd % p != 0) {
			std::cout << p << "\n";
			return;
		}
	}
	std::cout << -1 << "\n";

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