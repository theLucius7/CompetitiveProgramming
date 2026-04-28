#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b;
	std::cin >> a >> b;

	if (a == 1 || b == 1) {
		std::cout << -1 << "\n";
	} else {
		std::cout << 1 << "\n";
	}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();}

	}

	return 0;
}`