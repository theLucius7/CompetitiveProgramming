#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> A(N);
	for (int i = 0; i < N; i++) {
		int L;
		std::cin >> L;
		A[i].resize(L);
		for (int j = 0; j < L; j++) {
			std::cin >> A[i][j];
		}
	}

	int X, Y;
	std::cin >> X >> Y;
	X--, Y--;

	std::cout << A[X][Y] << "\n";

	return 0;
}