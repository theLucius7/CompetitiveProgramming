#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != i + 1) {
			int f = a[i];
			for (int j = i + 1; j < f; j++) {
				f = std::max(f, a[j]);
			}
			ans += f - i;
			i = f - 1;
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