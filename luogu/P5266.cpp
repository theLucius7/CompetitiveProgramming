#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Q;
	std::cin >> Q;

	std::map<std::string, int> map;
	while (Q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			std::string name;
			int score;
			std::cin >> name >> score;
			map[name] = score;
			std::cout << "OK\n";
		} else if (op == 2) {
			std::string name;
			std::cin >> name;
			if (!map.contains(name)) {
				std::cout << "Not found\n";
			} else {
				std::cout << map[name] << "\n";
			}
		} else if (op == 3) {
			std::string name;
			std::cin >> name;
			if (!map.contains(name)) {
				std::cout << "Not found\n";
			} else {
				map.erase(name);
				std::cout << "Deleted successfully\n";
			}
		} else {
			std::cout << map.size() << "\n";
		}
	}

	return 0;
}