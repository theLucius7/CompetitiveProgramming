#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, M;
	std::cin >> n >> M;

	std::vector<i64> A(n - 1);
	for (int i = 0; i < n - 1; i++) {
		std::cin >> A[i];
	}

	std::vector<i64> B(n);
	int x;
	for (int i = 0; i < n - 2; i++) {
		if (A[i] != A[i + 1]) {
			B[i + 1] = std::gcd(A[i], A[i + 1]);
			x = i;
			break;
		}
	}

	for (int i = x; i >= 0; i--) {
		B[i] = A[i] / B[i + 1];
	}

	for (int i = x + 2; i < n; i++) {
		B[i] = A[i - 1] / B[i - 1];
	}

	for (int i = 0; i < n; i++) {
		if (B[i] > M) {
			std::cout << "-1\n";
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << B[i] << " \n"[i == n - 1];
	}
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