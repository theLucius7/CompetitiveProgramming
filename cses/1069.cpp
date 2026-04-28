#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	char c = s[0];
	int ans = 0, now = 1;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] == c) {
			now++;
		} else {
			ans = std::max(ans, now);
			c = s[i];
			now = 1;
		}
	}

	ans = std::max(ans, now);
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}