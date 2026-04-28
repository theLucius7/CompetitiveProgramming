#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n, a, b;
	std::cin >> n >> a >> b;

	std::cout << ((((n ^ b) % 2 == 0) && ((a <= b) || ((n ^ a) % 2 == 0))) ? "YES\n" : "NO\n");
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