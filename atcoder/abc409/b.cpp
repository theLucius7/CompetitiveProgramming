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

	for (int x = 100; x >= 0; x--) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] >= x) {
				cnt++;
			}
		}
		if (cnt >= x) {
			std::cout << x << "\n";
			return 0;
		}
	}

	return 0;
}