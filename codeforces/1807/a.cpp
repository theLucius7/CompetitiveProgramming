#include <bits/stdc++.h>

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;

	std::cout << (a + b == c ? "+" : "-") <<  "\n";
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