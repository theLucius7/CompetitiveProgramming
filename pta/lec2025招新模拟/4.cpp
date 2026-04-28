#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a;
	std::cin >> a;

	if (a >= 90) {
		std::cout << "A\n";
	} else if (a >= 80) {
		std::cout << "B\n";
	} else if (a >= 70) {
		std::cout << "C\n";
	} else if (a >= 60) {
		std::cout << "D\n";
	} else {
		std::cout << "E\n";
	}

	return 0;
}