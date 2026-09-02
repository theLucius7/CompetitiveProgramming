#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		bool ok = false;
		for (int j = i - 1; j >= 0; j--) {
			if (A[j] > A[i]) {
				std::cout << j + 1 << "\n";
				ok = true;
				break;
			}
		}
		if (!ok) {
			std::cout << -1 << "\n";
		}
	}

	return 0;
}