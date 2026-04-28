#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	i64 sum = 1500;
	for (int i = 0; i < n; i++) {
		i64 c;
		std::cin >> c;

		sum += c;

		if (sum >= 4000) {
			std::cout << i + 1 << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";

	return 0;
}