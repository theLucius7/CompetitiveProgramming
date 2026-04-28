#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i == (s.size() + 1) / 2 - 1) {
			continue;
		}
		std::cout << s[i];
	}

	return 0;
}