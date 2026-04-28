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

	i64 ans = a[0];
	for (int i = 1; i < n; i++) {
		int min = INT_MAX;
		for (int j = i - 1; j >= 0; j--) {
			min = std::min(min, std::abs(a[j] - a[i]));
		}
		ans += min;
	}
	std::cout << ans << "\n";

	return 0;
}