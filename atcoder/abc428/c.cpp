#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Q;
	std::cin >> Q;

	std::vector<int> A{0}, B{0};
	while (Q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			char c;
			std::cin >> c;

			A.push_back(A.back() + (c == '(' ? 1 : -1));
			B.push_back(std::min(A.back(), B.back()));
		} else {
			A.pop_back();
			B.pop_back();
		}

		std::cout << ((A.back() == 0 && B.back() == 0) ? "Yes" : "No") << "\n";
	}

	return 0;
}