#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	for (int i = 0; i < (1 << n); i++) {
		std::cout << (i ^ (i >> 1)) << " \n"[i == ((1 << n) - 1)];
	}

	return 0;
}