#include <bits/stdc++.h>

using i64 = long long;

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, a;
	std::cin >> n >> m >> a;
	
	std::cout << (i64)ceil (1.0 * n / a) * (i64)ceil (1.0 * m / a) << "\n";
	
	return 0;
} 