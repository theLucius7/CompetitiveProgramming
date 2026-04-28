#include <bits/stdc++.h>

using i64 = long long;

i64 n = 600851475143;

void solve () {
	while (n % 2 == 0) {
		n /= 2;
	}

	int factor = 3, maxfactor = sqrt (n);

	while (n > 1 && factor <= maxfactor) {
		while (n % factor == 0) {
			n /= factor;
		}

		factor += 2;

		maxfactor = sqrt (n);
	}

	if (n == 1) {
		std::cout << factor - 2 << "\n";
	} else {
		std::cout << n << "\n";
	}
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve ();

	return 0;
}