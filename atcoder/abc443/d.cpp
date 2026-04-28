#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N;
	std::cin >> N;

	std::vector<int> R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> R[i];
	}


	std::vector<int> A(N);
    A[0] = R[0];
    for (int i = 1; i < N; i++) {
        A[i] = std::min(R[i], A[i - 1] + 1);
    }

    std::vector<int> B(N);
    B[N - 1] = R[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        B[i] = std::min(R[i], B[i + 1] + 1);
    }

    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        ans += R[i] - std::min(A[i], B[i]);
    }

    std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}