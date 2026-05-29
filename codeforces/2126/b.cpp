#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ) {
		int j = i + 1;
		if (a[i] == 0) {
			while (j < n && a[j] == 0) {
				j++;
			}
			int len = j - i;
			if (len >= k) {
				len -= k;
				ans++;
			}
			ans += len / (k + 1);
		}
		i = j;
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