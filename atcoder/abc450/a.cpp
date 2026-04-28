#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	for (int i = N; i >= 1; i--) {
		std::cout << i << ",\n"[i == 1];
	}

	return 0;
}