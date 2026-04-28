#include <bits/stdc++.h>

using i64 = long long;

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	for (auto &c : S) {
		c = std::toupper(c);
	}

	std::cout << S << "\n";

	return 0;
}