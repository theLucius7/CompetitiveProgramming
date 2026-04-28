#include <bits/stdc++.h>

using i64 = long long;

int main () {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i ++ ) {
		std::cout << i << " \n"[i == n];
	}	

	return 0;
}