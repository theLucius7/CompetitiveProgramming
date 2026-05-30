#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::sort(A.begin(), A.end());

	while (Q--) {
		int x;
		std::cin >> x;

		auto it = std::lower_bound(A.begin(), A.end(), x);

		std::cout << (it == A.end() ? 0 : N - (it - A.begin())) << "\n";
	}

	return 0;
}