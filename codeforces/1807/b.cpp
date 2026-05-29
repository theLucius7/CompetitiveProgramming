#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;

	int x = 0;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		x += (a % 2 == 0 ? a : -a);
	}

	std::cout << (x > 0 ? "YES" : "NO") << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}