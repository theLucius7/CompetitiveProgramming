#include <bits/stdc++.h>

using u64 = unsigned long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	u64 a = 0;
	for (int i = 0; i < 64; i++) {
		u64 x;
		std::cin >> x;
		a += (x << i);
	}
	std::cout << a << "\n";

	return 0;
}