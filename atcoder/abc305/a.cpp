#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	if (n % 5 <= 2) {
		std::cout << n - n % 5 << "\n";
	} else {
		std::cout << n + 5 - n % 5 << "\n";
	}

	return 0;
}