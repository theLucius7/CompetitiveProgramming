#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Q;
	std::cin >> Q;

	std::multiset<int> S;

	while (Q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int x;
			std::cin >> x;

			S.insert(x);
		} else {
			auto it = S.begin();
			std::cout << *it << "\n";
			S.erase(it);
		}
	}

	return 0;
}