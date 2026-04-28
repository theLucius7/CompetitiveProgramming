#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<std::pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		A[i].first = 0;
		A[i].second = i + 1;
	}

	for (int i = 0; i < Q; i++) {
		int X;
		std::cin >> X;

		if (X >= 1) {
			for (int j = 0; j < N; j++) {
				if (A[j].second == X) {
					A[j].first++;
					std::cout << A[j].second << " ";
				}
			}
		} else {
			std::sort(A.begin(), A.end());
			A[0].first++;
			std::cout << A[0].second << " ";
		}
	}

	return 0;
}