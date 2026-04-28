#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[0]) {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";

	return 0;
}