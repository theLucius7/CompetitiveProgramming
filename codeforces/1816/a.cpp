#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int a, b;
	std::cin >> a >> b;

	std::cout << 2 << "\n";
	std::cout << a - 1 << " " << 1 << "\n";
	std::cout << a << " " << b << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t -- ) {
		solve ();
	}

	return 0;
}