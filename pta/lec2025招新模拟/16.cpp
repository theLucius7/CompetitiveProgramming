#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	int sum = 0;
	for (char c : s) {
		sum += c - '0';
	}
	std::cout << s.size() << " " << sum << "\n";

	return 0;
}