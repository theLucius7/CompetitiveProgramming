#include <bits/stdc++.h>

#define int long long

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int ans = 0;
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && s[r] == s[l]) {
			r++;
		}
		ans += std::max(0LL, r - l - 1);
		// std::cout << l << " " << r << "\n";
	}
	std::cout << ans << "\n";

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}