#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	if (S == "red") {
		std::cout << "SSS\n";
	} else if (S == "blue") {
		std::cout << "FFF\n";
	} else if (S == "green") {
		std::cout << "MMM\n";
	} else {
		std::cout << "Unknown\n";
	}

	return 0;
}