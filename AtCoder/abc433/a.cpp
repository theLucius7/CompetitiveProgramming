#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int X, Y, Z;
	std::cin >> X >> Y >> Z;

	std::cout << (((X - Y * Z) % (Z - 1) == 0) && ((X - Y * Z) / (Z - 1) >= 0) ? "Yes" : "No") << "\n";

	return 0;
}