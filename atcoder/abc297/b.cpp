#include <bits/stdc++.h>

constexpr int inf = 0x3f3f3f3f;

using i64 = long long;

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	int x = S.find ('B');
	int y = S.find ('B', x + 1);

	if (x % 2 == y % 2) {
		std::cout << "No\n";
		return 0;
	}

	x = S.find ('R');
	y = S.find ('R', x + 1);

	int z = S.find ('K');

	if (z < x || y < z) {
		std::cout << "No\n";
		return 0;
	}

	std::cout << "Yes\n";

	return 0;
}