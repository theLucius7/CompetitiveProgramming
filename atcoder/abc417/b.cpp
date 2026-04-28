#include <bits/stdc++.h>

using i64 = long long;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	for (int i = 0; i < M; i++) {
		int B;
		std::cin >> B;

		auto it = std::lower_bound(A.begin(), A.end(), B);
		if (it != A.end() && *it == B) {
			A.erase(it);
		}
	}

	for (int i = 0; i < A.size(); i++) {
		std::cout << A[i] << " \n"[i == A.size() - 1];
	}

	return 0;
}