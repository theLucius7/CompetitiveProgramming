#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, T;
	std::cin >> N >> T;

	std::vector<int> A(N + 1);
	A[N] = T;
	int cur = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	for (int i = 0; i <= N; i++) {
		if (cur <= A[i]) {
			ans += A[i] - cur;
			cur = A[i] + 100;
		}
	}
	std::cout << ans << "\n";

	return 0;
}