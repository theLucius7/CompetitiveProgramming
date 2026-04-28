#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, k;
	std::cin >> n >> k;

	int ans = 0;

	i64 cnt[60] {};
	for (int i = 0; i < n; i++) {
		i64 a;
		std::cin >> a;

		ans += __builtin_popcountll(a);

		for (int i = 0; i < 60; i++) {
			if (~a >> i & 1) {
				cnt[i]++;
			}
		}
	}

	for (int i = 0; i < 60; i++) {
		i64 t = std::min(cnt[i], k >> i);
		k -= t << i;
		ans += t;
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

