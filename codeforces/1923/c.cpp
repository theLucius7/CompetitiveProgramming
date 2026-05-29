#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

#define int long long

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> sum(n + 1), cnt(n + 1);
	for (int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + a[i];
		cnt[i + 1] = cnt[i] + (a[i] == 1);
	}

	while (q--) {
		int l, r;
		std::cin >> l >> r;
		l--, r--;
		if (l == r) {
			std::cout << "NO\n";
		} else {
			int s = sum[r + 1] - sum[l], c = cnt[r + 1] - cnt[l];
			// std::cout << s << " " << c << "\n";
			if (s / (r - l + 1) == 1 && s % (r - l + 1) < c) {
				std::cout << "NO\n";
			} else {
				std::cout << "YES\n";
			}
		}
	}
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