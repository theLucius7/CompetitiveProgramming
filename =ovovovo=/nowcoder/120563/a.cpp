#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x;
	std::cin >> x;

	for (int i = 1; i <= 100; i++) {
		if (x == i * (i + 1)) {
			std::cout << "YES\n";
			return 0;
		}
	}

	std::cout << "NO\n";

	return 0;
}