#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());

	int x = (4 * (n - 1) + 4) / 5;
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		if (std::upper_bound(a.begin(), a.end(), a[i]) - a.begin() - 1 >= x) {
			ans += a[i];
		}
	}
	std::cout << ans << "\n";

	return 0;
}