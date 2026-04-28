#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	// for (int i = 0; i < n; i++) {
	// 	cnt += (s[i] == '1');
	// }
	int cnt = std::count(s.begin(), s.end(), '1');

	// std::cout << cnt << "\n";
	std::cout << cnt * (n - 1) + (n - cnt) << "\n";
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