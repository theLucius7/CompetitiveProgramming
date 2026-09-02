#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, P, Q;
	std::cin >> N >> P >> Q;

	std::vector<int> D(N);
	for (int i = 0; i < N; i++) {
		std::cin >> D[i];
	}

	int res = P;
	for (int i = 0; i < N; i++) {
		res = std::min(res, Q + D[i]);
	}

	std::cout << res << "\n";


	return 0;
}