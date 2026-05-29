#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr i64 P = 998244353;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> A(N), B(M);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		std::cin >> B[i];
	}

	i64 sum_iA = 0, sumB = 0;
	for (int i = 0; i < N; i++) {
		sum_iA += (i + 1) * A[i];
		sum_iA %= P;
	}
	for (int i = 0; i < M; i++) {
		sumB += B[i];
		sumB %= P;
	}

	std::vector<i64> suf(N + 1);
	for (int i = N - 1; i >= 0; i--) {
		suf[i] = suf[i + 1] + A[i];
		suf[i] %= P;
	}
	i64 sumABx = 0;
	for (int j = 1; j <= M; j++) {
		i64 x = 0;
		for (int i = j; i <= N; i += j) {
			x += suf[i - 1];
			x %= P;
		}
		sumABx += x * B[j - 1] % P * j % P;
		sumABx %= P;
	}

	std::cout << ((sum_iA * sumB) % P - sumABx + P) % P << "\n";


	return 0;
}