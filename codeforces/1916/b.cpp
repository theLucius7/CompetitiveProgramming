#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b;
	std::cin >> a >> b;

	if (b % a == 0) {
		std::cout << b * b / a << "\n";
	} else {
		std::cout << a * b / std::gcd(a, b) << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}