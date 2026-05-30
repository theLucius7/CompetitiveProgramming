#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<i64> A(N);
	for (int i = 0; i < N; i++) {
		A[i] = i + 1;
	}

	int first = 0;

	while (Q--) {
		int type;
		std::cin >> type;

		if (type == 1) {
			i64 p, x;
			std::cin >> p >> x;

			A[((p + first - 1) % N + N) % N] = x; 
		} else if (type == 2) {
			i64 p;
			std::cin >> p;

			std::cout << A[((p + first - 1) % N + N) % N] << "\n";
		} else {
			i64 k;
			std::cin >> k;

			first = ((first + k) % N + N) % N;
		}
	}

	return 0;
}