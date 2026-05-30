#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	int k;
	std::cin >> n >> k;

	auto is_prime = [&](i64 x) {
		if (x == 1) {
			return false;
		}

		for (int i = 2; (i64)i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	};

	if ((k == 1 && is_prime(n))) {
		std::cout << "YES\n";
		return;
	}

	if (n == 1 && k == 2) {
		std::cout << "YES\n";
		return;
	}

	std::cout << "NO\n";
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