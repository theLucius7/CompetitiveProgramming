#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int max = n;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		max = std::max(max, a);
	}
	std::cout << max << "\n";
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