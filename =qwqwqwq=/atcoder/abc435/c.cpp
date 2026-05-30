#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	int r = 1;
	for (int i = 0; i < r; i++) {
		r = std::min(N, std::max(r, A[i] + i));
	}

	std::cout << r << "\n";

	return 0;
}