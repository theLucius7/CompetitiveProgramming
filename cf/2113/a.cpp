#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int k, a, b, x, y;
	std::cin >> k >> a >> b >> x >> y;

	if (a > b) {
		k -= x;
		if (x > b) {
			k -= y;
		}
	} else if (a == b) {
		k -= std::min()
	}
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