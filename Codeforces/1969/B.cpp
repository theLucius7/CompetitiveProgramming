#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

#define int long long

void solve() {
	std::string s;
	std::cin >> s;

	const int n = s.size();
	std::vector<std::pair<char, int>> v;
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && s[l] == s[r]) {
			r++;
		}
		v.push_back({s[l], r - l});
	}

	// for (int i = 0; i < v.size(); i++) {
	// 	std::cout << v[i].first << " " << v[i].second << "\n";
	// }

	int sum = 0, ans = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		auto [c, cnt] = v[i];
		if (c == '1') {
			sum += cnt;
			ans += (sum + 1) * v[i + 1].second;
		}
	}
	std::cout << ans << "\n";

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}