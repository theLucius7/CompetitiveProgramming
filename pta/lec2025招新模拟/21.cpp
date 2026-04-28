#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout <<  j << "*" << i << "=" << std::left << std::setw(4) << i * j;
		}
		std::cout << "\n";
	}

	return 0;
}	