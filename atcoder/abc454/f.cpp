#include <bits/stdc++.h>

using i64 = long long;

#define int long long

void solve() {
	int N, M;
	std::cin >> N >> M;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	N /= 2;
	for (int i = 0; i < N; i++) {
		A[i] = (A[i] - A.end()[-1 - i] + M) % M;
	}

	A.resize(N);
	for (int i = N - 1; i >= 1; i--) {
		A[i] = (A[i] - A[i - 1] + M) % M; 
	}

	std::sort(A.begin(), A.end());

	int suf = 0, pre = 0;
	for (int i = 0; i < N; i++) {
		suf += M - A[i];
	}
	int ans = std::max(pre, suf);
	for (int i = 0; i < N; i++) {
		pre += A[i];
		suf -= M - A[i];
		ans = std::min(ans, std::max(pre, suf));
	}
	std::cout << ans << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}