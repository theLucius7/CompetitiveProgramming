#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int d;
	std::cin >> d;

	std::cout << (d + 1) % 7 + 1 << "\n";

	return 0;
}