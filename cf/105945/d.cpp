#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	std::cin >> n;

	i64 ans = n % 10;
	n /= 10;

	int cnt = 1;
	while (n) {
		ans += (n % 10) * std::pow(2, cnt);
		n /= 10;
		cnt++;
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