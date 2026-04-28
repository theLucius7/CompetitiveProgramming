#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int K;
	std::cin >> K;

	if ((K & (K - 1)) == 0) {
		std::cout << K << " " << 0 << "\n";
	} else {
		int x = 32 - __builtin_clz(K);
		int y = __builtin_ctz(K);
		std::cout << (1 << x) << " " << x - y << "\n";
	}


	return 0;
}