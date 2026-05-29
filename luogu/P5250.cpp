#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m;
	std::cin >> m;

	std::set<int> s;
	while (m--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int x;
			std::cin >> x;

			auto it = s.lower_bound(x);
			if (it != s.end() && *it == x) {
				std::cout << "Already Exist\n";
				continue;
			}
			s.insert(x);
		} else {
			int x;
			std::cin >> x;

			if (s.empty()) {
				std::cout << "Empty\n";
				continue;
			}

			auto it = s.lower_bound(x);
			if (it == s.end()) {
				it--;
				std::cout << *it << "\n";
				s.erase(it);
				continue;
			} else if (it == s.begin()) {
				std::cout << *it << "\n";
				s.erase(it);
				continue;
			}

			int r = *it;
			it--;
			int l = *it;

			if (x - l <= r - x) {
				std::cout << l << "\n";
				s.erase(it);
			} else {
				std::cout << r << "\n";
				it++;
				s.erase(it);
			}
		}
	}

	return 0;
}