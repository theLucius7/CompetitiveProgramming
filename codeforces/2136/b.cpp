#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	int cnt = 0, res = 0;
	for (int i = 0; i <= n; i++) {
		if (i < n && s[i] == '1') {
			cnt++;
		} else {
			res = std::max(res, cnt);
			cnt = 0;
		}
	}
	if (res >= k) {
		std::cout << "NO" << "\n";
		return;
	}

	std::vector<int> a(n);
	int cur = n;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			a[i] = cur--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			a[i] = cur--;
		}
	}

	std::cout << "YES\n";
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " \n"[i == n - 1];
	}
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}