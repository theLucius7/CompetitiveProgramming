#include <bits/stdc++.h>

using i64 = long long;

i64 n = 600851475143;

void solve () {
	int factor = 2;

	while (n > 1) {
		while (n % factor == 0) {
			n /= factor;
		}
		factor ++ ;
	}

	std::cout << factor - 1 << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve ();

	return 0;
}