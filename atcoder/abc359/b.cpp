#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> A(2 * N);
	for (int i = 0; i < 2 * N; i++) {
		std::cin >> A[i];
	}

	int cnt = 0;
	for (int i = 0; i + 2 < 2 * N; i++) {
		cnt += (A[i] == A[i + 2]);
	}
	std::cout << cnt << "\n";

	return 0;
}