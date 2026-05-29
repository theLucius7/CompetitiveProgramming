#include <bits/stdc++.h>

using i64 = long long;

i64 n = 600851475143;

void solve () {
	while (n % 2 == 0) {
		n /= 2;
	}

	int factor = 3;

	while (n > 1) {
		while (n % factor == 0) {
			n /= factor;
		}
		factor += 2;
	}

	std::cout << factor - 2 << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve ();

	return 0;
}