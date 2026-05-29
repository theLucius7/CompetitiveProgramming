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

	std::sort(A.begin(), A.end());

	i64 sum = std::accumulate(A.begin(), A.end(), 0ll);
	int k = sum % N, av = sum / N;

	i64 res = 0;
	for (int i = 0; i < N; i++) {
		if (i < N - k) {
			res += std::abs(av - A[i]);
		} else {
			res += std::abs(av + 1 - A[i]);
		}
	}

	std::cout << res / 2 << "\n";

	return 0;
}