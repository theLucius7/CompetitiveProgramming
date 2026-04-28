#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::getline(std::cin, s);

	std::reverse(s.begin(), s.end());

	std::cout << s << "\n";

	return 0;
}