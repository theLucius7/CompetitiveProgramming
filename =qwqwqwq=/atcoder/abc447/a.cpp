#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::cout << (N / 2 + N % 2 >= M ? "Yes" : "No") << "\n";


	return 0;
}