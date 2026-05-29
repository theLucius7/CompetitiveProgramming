#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr real Pi = std::acos(-1);

	int D;
	std::cin >> D;

	std::cout << std::fixed << (real)D * D / 4 * Pi << "\n";

	return 0;
}