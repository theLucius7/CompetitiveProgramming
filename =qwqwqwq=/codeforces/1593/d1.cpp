#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	std::set<int> s;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		s.insert(a[i]);
	}

	int ans = -1;
	for (auto it = s.begin(); it != s.end(); it++) {
		auto nit = it;
		nit++;
		if (nit == s.end()) {
			break;
		}

		if (ans == -1) {
			ans = *nit - *it;
		} else {
			ans = std::gcd(ans, *nit - *it);
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