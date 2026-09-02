#include <bits/stdc++.h>

using i64 = long long;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b;
	std::cin >> a >> b;

	bool ok = false;
	auto check = [&](int x) {
		std::string s = std::to_string(x), t(s.rbegin(), s.rend());
		int y = std::stoi(s), m = std::stoi(t.substr(0, 2)), d = std::stoi(t.substr(2, 2));

		if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
			days[2] = 29;
		} else {
			days[2] = 28;
		}
		if (1 <= m && m <= 12 && d <= days[m]) {
			std::cout << s << t << "\n";
			ok = true;
		}
	};


	for (int i = a; i <= b; i++) {
		check(i);
	}

	while (!ok) {
		check(++b);
	}

	return 0;
}