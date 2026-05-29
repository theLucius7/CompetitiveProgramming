#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> a(3, std::vector<int>(3));
	std::vector<int> cnt(9);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> a[i][j];
			if (cnt[a[i][j] - 1]) {
				std::cout << "No\n";
				return 0;
			}
			cnt[a[i][j] - 1]++;
		}
	}

	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += a[i][j];
		}
		if (sum != 15) {
			std::cout << "No\n";
			return 0;
		}
	}

	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += a[j][i];
		}
		if (sum != 15) {
			std::cout << "No\n";
			return 0;
		}
	}

	if (a[0][0] + a[1][1] + a[2][2] != 15 || a[0][2] + a[1][1] + a[2][0] != 15) {
		std::cout << "No\n";
		return 0;
	}

	std::cout << "Yes\n";


	return 0;
}