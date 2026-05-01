#include <bits/stdc++.h>

std::string t = "codeforces";

void solve() {
	std::string s;
	std::cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans += s[i] != t[i];
	}
	std::cout << ans << "\n";
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