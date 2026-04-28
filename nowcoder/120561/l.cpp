#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x;
	std::cin >> x;

	if (x % 10 == 0) {
		std::cout << 1 << "\n";
	} else if (x % 2 == 0) {
		std::cout << 5 << "\n";
	} else if (x % 5 == 0) {
		std::cout << 2 << "\n";
	} else {
		std::cout << 10 << "\n";
	}


	return 0;
}