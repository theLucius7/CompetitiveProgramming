#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int suf = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		suf = (a[i] == 0) ? suf + 1 : 0;
		ans = std::max(ans, suf);
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