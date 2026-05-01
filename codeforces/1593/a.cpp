#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::array<int, 3> a;
	std::cin >> a[0] >> a[1] >> a[2];

	int max = -1, cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (a[i] > max) {
			max = a[i];
			cnt = 1;
		} else if (a[i] == max) {
			cnt++;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (a[i] == max) {
			if (cnt > 1) {
				std::cout << 1;
			} else {
				std::cout << 0;
			}
		} else {
			std::cout << max + 1 - a[i];
		}
		std::cout << " \n"[i == 2];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}