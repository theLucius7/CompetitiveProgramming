#include <bits/stdc++.h>

using i64 = long long;

int main () {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i ++ ) {
		double x, y, z;
		std::cin >> x >> y >> z;

		std::cout << x + y << "\n";
	}	

	return 0;
}