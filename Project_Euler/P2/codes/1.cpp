#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 4E6;

void solve () {
	int a = 1, b = 1, c;
	i64 res = 0;

	while (c < N) {
		if (b % 2 == 0) {
			res += c;
		}

		c = a + b;
		a = b;
		b = c;
	}

	std::cout << res << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve ();

	return 0;
}
