#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

#define int long long

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n), x(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}

	std::map<int, std::vector<int>> mp;
	for (int i = 0; i < n; i++) {
		mp[std::abs(x[i])].push_back(a[i]);
	}

	int l = 0, cnt = 0;
	for (auto [u, v] : mp) {
		cnt += (u - l) * k;
		l = u;
		for (int i = 0; i < v.size(); i++) {
			cnt -= v[i];
		}

		if (cnt < 0) {
			std::cout << "NO\n";
			return;
		}
	}

	std::cout << "YES\n";
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