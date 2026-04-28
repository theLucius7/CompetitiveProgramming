#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m, n;
	std::cin >> m >> n;

	std::vector<int> a(m), b(n);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	int x = 0;
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		while (x < m && b[i] > a[x]) {
			x++;
		}

		if (x == 0) {
			ans += a[x] - b[i];
		} else if (x == m) {
			ans += b[i] - a[x - 1];
		} else {
			ans += std::min(a[x] - b[i], b[i] - a[x - 1]);
		}

	}
	std::cout << ans << "\n";

	return 0;
}