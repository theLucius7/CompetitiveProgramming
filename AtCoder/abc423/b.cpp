#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> L(n);
	for (int i = 0; i < n; i++) {
		std::cin >> L[i];
	}

	int l = 0;

	for (int i = 0; i < n; i++) {
		if (L[i] == 1) {
			break;
		}
		l++;
	}

	int r = n;
	for (int i = n - 1; i >= 0; i--) {
		if (L[i] == 1) {
			break;
		}
		r--;
	}

	std::cout << std::max(0, r - l - 1) << "\n";

	return 0;
}