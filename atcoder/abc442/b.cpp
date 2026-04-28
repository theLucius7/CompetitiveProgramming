#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Q;
	std::cin >> Q;

	int a = 0;
	bool run = false;

	while (Q--) {
		int A;
		std::cin >> A;

		if (A == 1) {
			a++;
		} else if (A == 2) {
			a = std::max(0, a - 1);
		} else {
			run = !run;
		}

		std::cout << (run && a >= 3 ? "Yes" : "No") << "\n";
	}

	return 0;
}