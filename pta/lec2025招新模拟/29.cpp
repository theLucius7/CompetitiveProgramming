#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '6' && s[i] != '4' && s[i] != '8') {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";

	return 0;
}