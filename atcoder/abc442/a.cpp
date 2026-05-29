#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'i' || s[i] == 'j') {
			ans++;
		}
	}

	std::cout << ans << "\n";

	return 0;
}