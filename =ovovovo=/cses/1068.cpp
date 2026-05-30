#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a;
	std::cin >> a;

	while(a != 1) {
		std::cout << a << " ";
		if (a % 2) {
			a = a * 3 + 1;
		} else {
			a /= 2;
		}
	}
	std::cout << a << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}