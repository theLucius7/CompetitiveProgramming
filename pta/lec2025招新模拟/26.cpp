#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	i64 sum = 0;
	for (int i = 1; i <= N; i++) {
		i64 x = 1;
		for (int j = 1; j <= i; j++) {
			x *= j;
		}
		sum += x;
	}
	std::cout << sum << "\n";

	return 0;
}