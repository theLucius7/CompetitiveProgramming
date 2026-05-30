#include <bits/stdc++.h>

using i64 = long long;

bool check(int N, std::vector<i64> A) {
	int zheng = 0, fu = 0;
	for (int i = 0; i < N; i++) {
		if (std::abs(A[i]) != std::abs(A[0])) {
			return false;
		}
		if (A[i] < 0) {
			fu++;
		} else if (A[i] > 0) {
			zheng++;
		}
	}


	return std::abs(zheng - fu) <= 1;
}

void solve() {
	int N;
	std::cin >> N;

	std::vector<i64> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::sort(A.begin(), A.end(), [] (i64 x, i64 y) { return std::abs(x) < std::abs(y); });

	if (check(N, A)) {
		std::cout << "Yes\n";
		return;
	}

	for (int i = 1; i < N - 1; i++) {
		if ((i64)A[i] * A[i] != (i64)A[i + 1] * A[i - 1]) {
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while(T--) {
		solve();
	}

	return 0;
}