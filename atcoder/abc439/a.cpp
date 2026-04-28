#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::cout << ((1 << N) - 2 * N) << "\n";

	return 0;
}