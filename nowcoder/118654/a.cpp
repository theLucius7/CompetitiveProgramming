#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> a(n - 1);
	for (int i = 0; i < n - 1; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != i + 1) {
			std::cout << i + 1 << "\n";
			return 0;
		}
	}

	std::cout << n << "\n";

	return 0;
}