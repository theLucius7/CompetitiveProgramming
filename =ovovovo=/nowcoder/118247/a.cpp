#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, x;
	std::cin >> n >> x;

	int a = std::ceil(1.0 * n / 10);

	if (x <= a) {
		std::cout << "Gold Medal\n";
	} else if (x <= 3 * a) {
		std::cout << "Silver Medal\n";
	} else if (x <= 6 * a) {
		std::cout << "Bronze Medal\n";
	} else {
		std::cout << "Da Tie\n";
	}

	return 0;
}