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

	if (M >= std::accumulate(A.begin(), A.end(), 0)) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}

	return 0;
}