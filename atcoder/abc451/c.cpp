#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Q;
	std::cin >> Q;

	std::multiset<int> s;
	while (Q--) {
		int op, h;
		std::cin >> op >> h;

		if (op == 1) {
			s.insert(h);
			std::cout << s.size() << "\n";
		} else {
			for (auto it = s.begin(); it != s.end() && *it <= h; it = s.erase(it)) {

			}
			std::cout << s.size() << "\n";
		}
	}

	return 0;
}