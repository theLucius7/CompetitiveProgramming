#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> S(8);
	for (int i = 0; i < 8; i++) {
		std::cin >> S[i];
	}

	for (int i = 1; i < 8; i++) {
		if (S[i] < S[i - 1]) {
			std::cout << "No\n";
			return 0;
		}
	}

	for (int i = 0; i < 8; i++) {
		if (S[i] % 25 != 0) {
			std::cout << "No\n";
			return 0;
		}
	}

	if (S[0] < 100 || S[7] > 750) {
		std::cout << "No\n";
		return 0;
	}

	std::cout << "Yes\n";

	return 0;
}