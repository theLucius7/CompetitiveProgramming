#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N;
	std::cin >> N;

	std::vector<std::array<i64, 2>> A(N);
	i64 sum = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> A[i][0] >> A[i][1];
		sum += A[i][1];
	}

	std::sort(A.begin(), A.end(), [&](auto x, auto y) {
		return x[0] + x[1] < y[0] + y[1];
	});

	i64 i = 0;
	for (i64 s = 0; s <= sum; s += A[i][0] + A[i][1], i++);

	std::cout << i - 1 << "\n";
	
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