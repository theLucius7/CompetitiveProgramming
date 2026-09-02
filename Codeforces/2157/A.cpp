#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	std::unordered_map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		cnt[a[i]]++;
	}

	int ans = 0;
	for (auto [k, v] : cnt) {
		if (v > k) {
			ans += v - k;
		} else if (v < k) {
			ans += v;
		}
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