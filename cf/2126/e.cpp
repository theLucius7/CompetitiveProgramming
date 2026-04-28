#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n), s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	bool ok = true;
	for (int i = 0; i < n - 1; i++) {
		if (p[i] % p[i + 1] != 0) {
			ok = false;
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (s[i] % s[i - 1] != 0) {
			ok = false;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (std::gcd(p[i], s[i + 1]) != p[n - 1]) {
			ok = false;
		}
	}

	if (p[n - 1] != s[0]) {
		ok = false;
	}

	std::cout << (ok ? "YES" : "NO") << "\n";

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