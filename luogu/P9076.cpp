#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 n;
	std::cin >> n;

	int cnt = 0;
	auto check = [&](int x) {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				if (i * i == x) {
					if (i > 1 && x / i > 2) {
						cnt++;
					}
				} else {
					if (i > 1 && x / i > 2) {
						cnt++;
					}
					if (x / i > 1 && i > 2) {
						cnt++;
					}
				}
			}
		}
	};

	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i * i == n) {
				check(i - 1);
			} else {
				check(i - 1);
				check(n / i - 1);
			}
		}
	}

	std::cout << cnt << "\n";

	return 0;
}