#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K, X;
	std::cin >> N >> K >> X;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		std::cout << A[i] << " ";
		if (i == K - 1) {
			std::cout << X << " ";
		}
	}

	return 0;
}