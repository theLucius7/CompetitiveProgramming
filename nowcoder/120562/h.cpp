#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::unordered_map<int, int> last;
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		if (!last.contains(a[i])) {
			ans += 1LL * (i + 1) * (n - i) * (n - i + 1) / 2;
		} else {
			ans += 1LL * (i - last[a[i]]) * (n - i) * (n - i + 1) / 2;
		}
		last[a[i]] = i;
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