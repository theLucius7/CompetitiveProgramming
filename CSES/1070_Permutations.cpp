#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	if (n == 2 || n == 3) {
		std::cout << "NO SOLUTION\n";
		return;
	}
	if (n == 4) {
		std::cout << "3 1 4 2\n";
		return;
	}

	for (int i = n; i >= 1; i -= 2) {
		std::cout << i << " ";
	}
	for (int i = n - 1; i >= 1; i -= 2) {
		std::cout << i << " \n"[i - 2 < 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}