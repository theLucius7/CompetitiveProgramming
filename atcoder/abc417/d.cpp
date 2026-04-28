#include <bits/stdc++.h>

using i64 = long long;

constexpr int K = 10001;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> P(N), A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i] >> A[i] >> B[i];
	}

	std::vector dp(N + 1, std::vector<int>(K));

	return 0;
}