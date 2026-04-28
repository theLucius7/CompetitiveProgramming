#include <bits/stdc++.h>

using i64 = long long;

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i ++ ) {
		int x;
		std::cin >> x;
		if (x % 2 == 0) {
			std::cout << x << " ";
		}
	}
	std::cout << "\n";

	return 0;
}