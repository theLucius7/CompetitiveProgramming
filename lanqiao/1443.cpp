#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << 3181 << "\n";
	return 0;

	std::vector<int> cnt(10, 2021);

	for (int i = 1; ; i++) {
		std::string s = std::to_string(i);
		for (auto c : s) {
			if (cnt[c - '0'] == 0) {
				std::cout << i - 1 << "\n";
				return 0;
			}

			cnt[c - '0']--;
		}
	}

	return 0;
}