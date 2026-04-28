#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, R;
	std::cin >> N >> R;

	std::vector<int> L(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i];
	}

	int l = 0, r = N - 1;
	while (L[l] == 1) {
		l++;
	}
	while (L[r] == 1) {
		r--;
	}

	i64 sum = 0;
	for (int i = l; i < R; i++) {
		sum += (L[i] == 1) * 2;

		sum += L[i] == 0;
	}

	for (int i = R; i <= r; i++) {
		sum += (L[i] == 1) * 2;
		sum += L[i] == 0;
	}
	std::cout << sum << "\n";

	return 0;
}