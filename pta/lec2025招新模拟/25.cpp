#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H;
	std::cin >> H;

	std::cout << std::fixed << std::setprecision(1) << 2 * (H - 100) * 0.9 << "\n";

	return 0;
}