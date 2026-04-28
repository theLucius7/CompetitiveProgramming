#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x = 1, y = 1;

	std::map<std::pair<int, int>, int> map;
	map[{0, 0}] = 2;
	map[{0, 1}] = 1;
	map[{0, 2}] = 0;
	map[{0, 3}] = 3;
	map[{1, 0}] = 1;
	map[{1, 1}] = 0;
	map[{1, 2}] = 3;
	map[{1, 3}] = 2;


	bool face = false;
	int now = 2;

	std::string test = "012345";
	for (int i = 0; i < test.size(); i++) {
		if (test[i] == '0') {
			face = !face;
		} else if (test[i] == '1') {
			face = !face;
			if (now == 2) {
				now = 1;
			} else if (now == 3) {
				now = 0;
			} else if (now == 0) {
				now = 3;
			} else {
				now = 2;
			}
		} else if (test[i] == '2') {
			face = !face;
			if (now == 2) {
				now = 0;
			} else if (now == 0) {
				now = 2;
			} 
		} else if (test[i] == '3') {
			face = !face;
			if (now == 0) {
				now = 1;
			} else if (now == 1) {
				now = 0;
			} else if (now == 2) {
				now = 3;
			} else {
				now = 2;
			}
		} else if (test[i] == '5') {
			now += 1;
			now %= 4;
		} else {
			now -= 1;
			now = (now + 4) % 4;
		}
		// std::cout << face << " " << now << " ";
		// std::cout << map[{face, now}];
		// std::cout << "\n";
	}
	// std::cout << "\n";

	// 310232

	face = false;
	now = 2;
	std::string op = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '0') {
			face = !face;
		} else if (op[i] == '1') {
			face = !face;
			if (now == 2) {
				now = 1;
			} else if (now == 3) {
				now = 0;
			} else if (now == 0) {
				now = 3;
			} else {
				now = 2;
			}
		} else if (op[i] == '2') {
			face = !face;
			if (now == 2) {
				now = 0;
			} else if (now == 0) {
				now = 2;
			} 
		} else if (op[i] == '3') {
			face = !face;
			if (now == 0) {
				now = 1;
			} else if (now == 1) {
				now = 0;
			} else if (now == 2) {
				now = 3;
			} else {
				now = 2;
			}
		} else if (op[i] == '5') {
			now += 1;
			now %= 4;
		} else {
			now -= 1;
			now = (now + 4) % 4;
		}
		// std::cout << face << " " << now << " ";
		std::cout << map[{face, now}];
		// std::cout << "\n";
	}
	std::cout << "\n";


	return 0;
}