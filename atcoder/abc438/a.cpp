#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int D, F;
	std::cin >> D >> F;

	std::cout << 7 - (D - F) % 7 << "\n";

	
	return 0;
}