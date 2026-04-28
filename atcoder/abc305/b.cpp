#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> a = {0, 3, 4, 8, 9, 14, 23};

	char p, q;
	std::cin >> p >> q;

	std::cout << std::abs(a[p - 'A'] - a[q - 'A']) << "\n";

	return 0;
}