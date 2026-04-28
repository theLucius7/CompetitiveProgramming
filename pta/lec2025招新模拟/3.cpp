#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> a(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());

	for (int i = 0; i < 3; i++) {
		std::cout << a[i];
		if (i != 2) {
			std::cout << "->";
		} else {
			std::cout << "\n";
		}
	}

	return 0;
}