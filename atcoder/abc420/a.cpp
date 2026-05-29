#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	int X, Y;
	std::cin >> X >> Y;

	std::cout << (X + Y - 1) % 12 + 1 << "\n";


	return 0;
}