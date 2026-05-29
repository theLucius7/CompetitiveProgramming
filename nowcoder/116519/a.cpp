#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	u64 a;
	std::cin >> a;

	std::cout << (((a << 16) & 0xFFFF0000ull) | ((a >> 16) & 0xFFFFull)) << "\n";

	return 0;
}