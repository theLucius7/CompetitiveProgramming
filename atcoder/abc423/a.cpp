#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int X, C;
	std::cin >> X >> C;

	std::cout << X / (1000 + C) * 1000 << "\n";

	return 0;
}