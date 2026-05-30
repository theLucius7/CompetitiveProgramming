#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	i64 X;
	std::cin >> N >> K >> X;

	std::vector<i64> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::sort(A.begin(), A.end());

	i64 res = 0;
	for (int i = K - 1; i >= 0; i--) {
		res += A[i];
		if (res >= X) {
			std::cout << N - i << "\n";
			return 0;
		}
	}

	std::cout << -1 << "\n";

	return 0;
}