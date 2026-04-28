#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, x, a, b;
	std::cin >> n >> x >> a >> b;
	std::cout << std::fixed << std::setprecision(2) << (n * x * (double)a + n * (100 - x) * (double)b) / 100 << "\n";

	return 0;
}