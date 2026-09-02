#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E7 + 1;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	a[0] = k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i + 1];
	}

	int ans = a[0] + a[n];
	for (int i = 0; i < n; i++) {
		ans = std::max(ans, a[i] + a[i + 1]);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}