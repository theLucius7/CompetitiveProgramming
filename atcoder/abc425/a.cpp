#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += std::pow(-1, i) * std::pow(i, 3);
	}
	std::cout << sum << "\n";

	return 0;
}