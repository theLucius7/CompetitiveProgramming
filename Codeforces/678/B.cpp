#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int sum = 0;

	auto check = [&](int x) {
		if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) {
			return true;
		}
		return false;
	};

	for (int i = n; ; i++) {
		if (i % 400 == 0) {
			sum += 366;
		} else if (i % 100 == 0) {
			sum += 365;
		} else if (i % 4 == 0) {
			sum += 366;
		} else {
			sum += 365;
		}

		bool ok = (check (n) == check (i + 1));


		sum %= 7;
		if (sum == 0 && ok) {
			std::cout << i + 1 << "\n";
			return 0;
		}
	}

	return 0;
}