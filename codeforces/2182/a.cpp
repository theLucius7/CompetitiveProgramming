#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	std::cout << (s.find("2026") != std::string::npos || s.find("2025") ==  std::string::npos ? "0" : "1") << "\n";
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