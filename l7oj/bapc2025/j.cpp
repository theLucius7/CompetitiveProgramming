#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::cout << n << "\n";
	for (int i = 0; i < n; i++) {
		std::cout << 1 << " \n"[i == n - 1];
	}

	return 0;
}