#include <bits/stdc++.h>

#define int long long

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	std::string t = "AYEIOUyaeiou";

	for (int i = 0; i < s.size(); i++) {
		if (t.find(s[i]) == std::string::npos) {
			std::cout << "." << (char)std::tolower(s[i]);
		}
	}
	std::cout << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}