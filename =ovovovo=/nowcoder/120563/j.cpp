#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	int q;
	std::cin >> n >> q;

	while (q--) {
		i64 x;
		std::cin >> x;

		i64 d = std::__lg(x);
		std::cout << (std::min((1LL << (d + 1)) - 1, n) - (1LL << d) + 1) << "\n";
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