#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a;
	std::cin >> a;

	if (a <= 2000 || a > 2100) {
		std::cout << "Invalid year!\n";
		return 0;
	}

	bool ok = false;
	for (int i = 2001; i <= a; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
			std::cout << i << "\n";
			ok = true;
		}
	}

	if (!ok) {
		std::cout << "None\n";
	}

	return 0;
}