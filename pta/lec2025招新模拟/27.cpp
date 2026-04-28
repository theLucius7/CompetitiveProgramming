#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m, d, y;
	char c;
	std::cin >> m >> c >> d >> c >> y;

	std::cout << std::setfill('0') << std::setw(4) << y << c << std::setw(2) << m << c << std::setw(2) << d << "\n";

	return 0;
}