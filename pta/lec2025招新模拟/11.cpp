#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b;
	std::cin >> a >> b;

	int c = std::gcd(a, b);

	std::cout << c << " " << a / c * b << "\n";

	return 0;
}