#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::sort(A.begin(), A.end());

	int min = inf;
	for (int i = 0; i + N - K - 1 < N; i++) {
		min = std::min(min, A[i + N - K - 1] - A[i]);
	}
	std::cout << min << "\n";


	// int l = 0, r = N - 1;
	// for (int i = 0; i < K; i++) {
	// 	if (std::abs(A[l + 1] - A[r]) <= std::abs(A[l] - A[r - 1])) {
	// 		l++;
	// 	} else {
	// 		r--;
	// 	}
	// }
	// std::cout << std::abs(A[r] - A[l]) << "\n";

	return 0;
}