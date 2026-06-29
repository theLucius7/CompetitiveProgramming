#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int type, n, m, P;
	std::cin >> type >> n >> m >> P;

	i64 ans = 1;
	for (int i = n - 2 * m + 2; i <= n - m + 1; i++) {
		ans = ans * i % P;
	}
	std::cout << ans << "\n";

	return 0;
}