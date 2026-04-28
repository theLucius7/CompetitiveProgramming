#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	i64 ans = 1;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			ans += a[i] - b[i];
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}


	return 0;
}