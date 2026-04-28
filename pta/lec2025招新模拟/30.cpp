#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	int now = 0, ans = 0;
	for (int x = 0; x <= s.size(); x++) {
		if (x < s.size() && s[x] == '1') {
			now++;
		} else {
			ans += now * (now + 1) / 2;
			now = 0;
		}
	}

	std::cout << ans << "\n";

	return 0;
}