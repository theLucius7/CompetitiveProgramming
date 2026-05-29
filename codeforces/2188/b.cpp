#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	std::vector<bool> vis(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			vis[i] = true;
			if (i > 0) {
				vis[i - 1] = true;
			}
			if (i < n - 1) {
				vis[i + 1] = true;
			}
		}
	}

	int ans = std::count(s.begin(), s.end(), '1');
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (i < n && !vis[i]) {
			cnt++;
		} else {
			ans += (cnt + 2) / 3;
			cnt = 0;
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