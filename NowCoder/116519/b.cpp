#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	while (m--) {
		int x;
		std::cin >> x;

		auto t = std::lower_bound(a.begin(), a.end(), x);
		if (t != a.end() && *t == x) {
			std::cout << (t - a.begin() + 1) << " ";
		} else {
			std::cout << -1 << " ";
		}
	}

	return 0;
}