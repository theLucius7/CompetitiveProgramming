#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b;
	std::cin >> a >> b;

	std::pair<int, int> A{a, 0}, B{b, 1};
	if (b < a) {
		std::swap(A, B);
	}

	int x = B.first / (A.first + 1);
	int cnt = B.first % (A.first + 1);

	for (int i = 0; i < A.first + 1; i++) {
		for (int j = 0; j < (x + (cnt > 0)); j++) {
			std::cout << B.second;
		}
		if (cnt) {
			cnt--;
		}
		if (i != A.first) {
			std::cout << A.second;
		}
	}

	std::cout << "\n";

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