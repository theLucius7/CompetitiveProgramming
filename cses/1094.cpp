#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	for (int i = 1; i < a.size(); i++) {
		if (a[i] < a[i - 1]) {
			ans += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}