#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	std::unordered_map<i64, std::vector<int>> cnt;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 sqrtn = std::sqrt(n);
	real ans = 0;
	for (i64 x = 1; x <= sqrtn; x++) {
		for (int i = 0; i < n; i++) {
			if (x * a[i] + i >= 0 && x * a[i] + i < n && a[x * a[i] + i] == x) {
				if (a[i] <= sqrtn) {
					ans += 0.5;
				} else {
					ans++;
				}
			}
			if (i - x * a[i] >= 0 && i - x * a[i] < n && a[i - x * a[i]] == x) {
				if (a[i] <= sqrtn) {
					ans += 0.5;
				} else {
					ans++;
				}
			}
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