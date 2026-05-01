#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::cout << std::min(n + 1, 1 << std::min(30, k)) << "\n";
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