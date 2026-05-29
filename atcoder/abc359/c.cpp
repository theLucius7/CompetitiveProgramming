#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 Sx, Sy, Tx, Ty;
	std::cin >> Sx >> Sy >> Tx >> Ty;

	if ((Sx + Sy) % 2 != 0) {
		Sx--;
	}
	if ((Tx + Ty) % 2 != 0) {
		Tx--;
	}

	std::cout << std::abs(Ty - Sy) + std::max(0LL, std::abs(Tx - Sx) - std::abs(Ty - Sy)) / 2 << "\n";


	return 0;
}