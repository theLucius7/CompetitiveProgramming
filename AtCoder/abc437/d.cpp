#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr i64 P = 998244353;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<i64> A(N), B(M);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		std::cin >> B[i];
	}
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	i64 ans = 0;
	for (int i = 0; i < N; i++) {
		auto it = std::lower_bound(B.begin(), B.end(), A[i]);
		i64 l = it - B.begin();
		it = std::upper_bound(B.begin(), B.end(), A[i]);
		i64 r = B.end() - it;

		ans += 1LL * (l - r) * A[i];
		// std::cout << 1LL * (l - r) * A[i] << " \n"[i == N - 1];
		ans = (ans % P + P) % P;
	}


	for (int i = 0; i < M; i++) {
		auto it = std::lower_bound(A.begin(), A.end(), B[i]);
		i64 l = it - A.begin();
		it = std::upper_bound(A.begin(), A.end(), B[i]);
		i64 r = A.end() - it;

		ans += 1LL * (l - r) * B[i];
		// std::cout << 1LL * (l - r) * B[i] << " \n"[i == M - 1];
		ans = (ans % P + P) % P;
	}

	std::cout << ans << "\n";



	return 0;
}