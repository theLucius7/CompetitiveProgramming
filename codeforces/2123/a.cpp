#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a;
	std::cin >> a;

	std::cout << (a % 4 == 0 ? "Bob" : "Alice") << "\n";
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