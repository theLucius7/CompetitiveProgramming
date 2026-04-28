#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> P(N), C(N);
	std::vector<std::bitset<100>> F(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i] >> C[i];
		for (int j = 0; j < C[i]; j++) {
			int x;
			std::cin >> x;
			F[i][x - 1] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (P[i] <= P[j] && (F[i] & F[j]) == F[j] && (P[i] < P[j] || F[i] != F[j])) {
				std::cout << "Yes\n";
				return 0;
			}
		}
	}

	std::cout << "No\n";

	return 0;
}