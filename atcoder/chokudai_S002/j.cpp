#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}

	std::vector<int> da, db;
	for (int i = 1; i * i <= A[0]; i++) {
		if (A[0] % i == 0) {
			da.push_back(i);
			if (A[0] / i != i) {
				da.push_back(A[0] / i);
			}
		}
	}
	for (int i = 1; i * i <= B[0]; i++) {
		if (B[0] % i == 0) {
			da.push_back(i);
			if (B[0] / i != i) {
				da.push_back(B[0] / i);
			}
		}
	}

	int max = 1;
	for (int x : da) {
		bool ok = true;
		for (int i = 0; i < N; i++) {
			if ((A[i] % x != 0) && (B[i] % x != 0)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			max = std::max(max, x);
		}
	}
	for (int x : db) {
		bool ok = true;
		for (int i = 0; i < N; i++) {
			if ((A[i] % x != 0) && (B[i] % x != 0)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			max = std::max(max, x);
		}
	}

	std::cout << max << "\n";

	return 0;
}