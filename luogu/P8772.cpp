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

	std::vector<i64> pre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + a[i];
	}

	i64 ans = 0;
	for (int i = n - 1; i >= 1; i--) {
		ans += pre[i] * a[i];
	}
	std::cout << ans << "\n";


	return 0;
}