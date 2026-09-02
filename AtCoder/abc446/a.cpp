#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	std::cout << "Of";

	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			std::cout << (char)std::tolower(s[i]);
		} else {
			std::cout << s[i];
		}
	}

	return 0;
}