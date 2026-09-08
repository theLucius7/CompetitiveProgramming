#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x;
	std::cin >> x;

	std::cout << (x % 2 == 0 && x != 2 ? "YES" : "NO") << "\n";


	return 0;
}