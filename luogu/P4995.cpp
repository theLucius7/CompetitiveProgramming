#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i + 1];
	}

	std::sort(a.begin(), a.end());

	int l = 0, r = n;
	i64 ans = 0;
	while (l < r) {
		ans += 1LL * (a[r] - a[l]) * (a[r] - a[l]);
		l++;

		if (l < r) {
			ans += 1LL * (a[r] - a[l]) * (a[r] - a[l]);
			r--;
		}
	}
	std::cout << ans << "\n";

	return 0;
}