#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
		A[i] %= K;
	}

	std::sort(A.begin(), A.end());

	int min = A.back() - A.front();
	for (int i = 0; i < N - 1; i++) {
		min = std::min(min, A[i] + K - A[i + 1]);
	}
	std::cout << min << "\n";


	return 0;
}