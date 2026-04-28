#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	double m, y, r;
	std::cin >> m >> y >> r;

	std::cout << std::fixed << std::setprecision(2) << "interest = " << m * std::pow((1 + r), y) - m << "\n";

	return 0;
}