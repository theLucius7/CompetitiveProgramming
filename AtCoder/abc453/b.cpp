#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T, X;
	std::cin >> T >> X;

	int cur = -1;
	for (int i = 0; i <= T; i++) {
		int A;
		std::cin >> A;

		if (cur == -1 || std::abs(cur - A) >= X) {
			std::cout << i << " " << A << "\n";
			cur = A;
		}

	}

	return 0;
}	