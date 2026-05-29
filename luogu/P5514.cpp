#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans ^= a[i];
	}
	std::cout << ans << "\n";


	return 0;
}