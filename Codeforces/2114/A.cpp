#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int x = std::stoi(s);
	int q = std::sqrt(x);
	if (q * q != x) {
		std::cout << -1 << "\n";
		return;
	}

	std::cout << 0 << " " << q << "\n";
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