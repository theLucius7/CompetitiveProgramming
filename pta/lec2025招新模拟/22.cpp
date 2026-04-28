#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	std::reverse(s.begin(), s.end());

	auto pos = s.find_first_not_of('0');
	if (pos != std::string::npos) {
		std::cout << s.substr(pos) << "\n";
	} else {
		std::cout << "0\n";
	}

	return 0;
}	