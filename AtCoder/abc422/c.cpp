#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 na, nb, nc;
	std::cin >> na >> nb >> nc;

	i64 sum = na + nb + nc;
	std::cout << std::min({na, nc, sum / 3}) << "\n";
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