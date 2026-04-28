#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::unordered_map<char, i64> map;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		map[s[0]]++;
	}
	std::cout << map['L'] * map['E'] * map['C'] + map['L'] * map['E'] * map['W'] + map['E'] * map['C'] * map['W'] + map['L'] * map['C'] * map['W'] << "\n";

	return 0;
}