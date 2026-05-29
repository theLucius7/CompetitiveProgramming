#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	const int n = s.size();
	std::string x;
	for (int i = 0; i < n; i++) {
		x += "()";
	}
	std::string y = std::string(n, '(') + std::string(n, ')');

	if (x.find(s) == std::string::npos) {
		std::cout << "YES\n" << x << "\n";
	} else if (y.find(s) == std::string::npos) {
		std::cout << "YES\n" << y << "\n";
	} else {
		std::cout << "NO\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}
	

	return 0;
}