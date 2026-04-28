#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (int i = 1; i < 1000; i++) {
		std::string s = std::to_string(i);
		while (s.size() < 3) {
			s = '0' + s;
		}
		if (s[0] != s[1] && s[1] != s[2] && s[0] != s[2]) {
			std::cout << s << "\n";
		}
	}

	return 0;
}