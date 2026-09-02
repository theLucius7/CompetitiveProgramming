#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::map<std::pair<int, int>, bool> f;
	f[{1, 7}] = true;
	f[{3, 3}] = true;
	f[{5, 5}] = true;
	f[{7, 7}] = true;
	f[{9, 9}] = true;
	
	int M, D;
	std::cin >> M >> D;

	std::cout << (f[{M, D}] ? "Yes" : "No") << "\n";

	return 0;
}	