#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> a;
	int q;
	std::cin >> q;

	while(q--) {
		int op, x;
		std::cin >> op >> x;

		if (op == 1) {
			a.push_back(x);
		} else {
			std::cout << a[a.size() - 1 - x + 1] << "\n";
		}
	}

	return 0;
}