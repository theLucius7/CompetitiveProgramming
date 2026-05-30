#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<std::vector<int>> A(N);
	for (int i = 0; i < N; i++) {
		int L;
		std::cin >> L;
		A[i].resize(L);
		for (int j = 0; j < L; j++) {
			std::cin >> A[i][j];
		}
	}

	std::vector<int> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}

	for (int i = 0; i < N; i++) {
		if ((int)A[i].size() * C[i] >= K) {
			// std::cout << i << " " << ((K % C[i] == 0) ? C[i] - 1 : K % C[i] - 1) << "\n";
			std::cout << A[i][(K % (int)A[i].size() == 0) ? (int)A[i].size() - 1 : K % (int)A[i].size() - 1] << "\n";
			return 0;
		} else {
			K -= (int)A[i].size() * C[i];
		}
	}

	return 0;
}