#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b, c;
	std::cin >> a >> b >> c;

	for (int i = a; i <= b; i+=c) {
		std::cout << i << " ";
	}

	return 0;
}