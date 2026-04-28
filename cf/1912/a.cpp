#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 x;
	int k;
	std::cin >> x >> k;

	std::vector<std::array<i64, 2>> all;
	for (int i = 0; i < k; i++) {
		int l;
		std::cin >> l;

		std::vector<int> a(l);
		for (int j = 0; j < l; j++) {
			std::cin >> a[j];
		}

		std::vector<std::array<i64, 2>> stk;
		for (int j = l - 1; j >= 0; j--) {
			i64 x = 0, y = 0;
			x = std::min(a[j], 0);

			
		}
	}

	return 0;
}