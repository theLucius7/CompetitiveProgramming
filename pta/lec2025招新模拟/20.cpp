#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b;
	char c;
	std::cin >> a >> c >> b;

	if (c == '+') {
		std::cout << a + b;
	} else if (c == '-') {
		std::cout << a - b;
	} else if (c == '*') {
		std::cout << a * b;
	} else if (c == '/') {
		std::cout << a / b;
	} else if (c == '%') {
		std::cout << a % b;
	} else {
		std::cout << "ERROR\n";
	}

	return 0;
}