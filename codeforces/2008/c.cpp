#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 l, r;
	std::cin >> l >> r;

	i64 a = l, x = 1;
	int cnt = 0;
	for ( ; ; a += x++) {
		if (a <= r) {
			cnt++;
		} else {
			break;
		}
	}
	std::cout << cnt << "\n";
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