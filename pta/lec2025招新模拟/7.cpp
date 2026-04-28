#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x;
	std::cin >> x;

	if (x < 0) {
		std::cout << "Invalid Value!\n";
		return 0;
	}

	std::cout << "cost = " << std::fixed << std::setprecision(2) << (std::min(50, x) * 0.53 + std::max(x - 50, 0) * 0.58) << "\n";

	return 0;
}