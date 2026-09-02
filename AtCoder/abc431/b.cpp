#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int X;
	std::cin >> X;

	int N;
	std::cin >> N;

	std::vector<int> W(N);
	for (int i = 0; i < N; i++) {
		std::cin >> W[i];
	}

	int Q;
	std::cin >> Q;

	std::vector<bool> use(N);
	int sum = X;

	while (Q--) {
		int P;
		std::cin >> P;

		P--;

		if (use[P]) {
			use[P] = false;
			sum -= W[P];
		} else {
			use[P] = true;
			sum += W[P];
		}

		std::cout << sum << "\n";
	}

	return 0;
}